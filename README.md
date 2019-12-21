## CPMD2NX 
### A simple tool to convert a CPMD TRAJECTORY into NewtonX input folders.  
This tool reads a TRAJECTORY CPMD file and cuts it into TRAJ#'s folders ready to run NewtonX.
Source files are:
- cpmd2nx.sh 
- functions.h
- include.h  
- tests/ Folder including some tests. 

# ------                                                                                               #
# What's needed?                                                                                       # 
# 1) A TRAJECTORY (cpmd file),                                                                         #
# 2) a "ramdom" GEOMETRY.xyz file of the species you want to study (this file, also from cpmd, is      #
#    needed just to pick-up the correct atom order).                                                   #
# *) Additionally, you might also provide the usual control.dyn, job.cmd, Default.Route and JOB_AD     #
#    files that will be copied in each of the TRAJ# folders.                                           #
########################################################################################################
# OUTPUT                                                                                               #
# ------                                                                                               #
# Bunch of TRAJ# folders containing geom, veloc and GEOMETRY.xyz files.                                #
########################################################################################################
# PLT@EPFL(2014)                                                                                       #
########################################################################################################
#
######### DECLARE VARIABLES  
#
   declare -i i NATOMS CONT GEOMLINES step
   declare -a s control Zatom mass RX RY RZ VX VY VZ 
   declare -f mass_zatom check_file good_end 
#
######### INCLUDE & CHECK 
#
   . ./functions.h
#
   clear
#
   check_file control.dyn   control[1] 
   check_file JOB_AD        control[2]  
   check_file job.cmd       control[3]  
   check_file Default.Route control[4] # just for Gaussian parallel jobs
#
######### ASK WHETHER THE USER WANTS TO SELECT FRAMES OR NOT
#
   echo "Configurations will be taken one per step of the trajectory; do you agree? (Y/N)"
   read answ
   if [ $answ == Y ]; then let step=1 
    elif [ $answ == N ] ; then \
     echo "Configurations will be taken every N steps, where N is equal to?"
     read step; 
    else echo "I didn't understand, please run the script again." ; exit 
   fi
#
######### #NATOMS 
#
   GEOMLINES=$(wc -l GEOMETRY.xyz |sed s/GEOMETRY.xyz//g)
   NATOMS=$(($GEOMLINES-2))
   echo ""
   echo "I have read $NATOMS atoms from the GEOMETRY.xyz file"
   echo ""
   CONT=$NATOMS
#
   s=($(tail -n $NATOMS GEOMETRY.xyz | awk '{print $1}')) 
#
######### ASSESSING CHARGES AND ATOMIC NUMBER 
#
   for ((j=0;j<$NATOMS;j++)); do mass_zatom $j Zatom[$j] mass[$j]; done
# -----
   LINES=$(wc -l TRAJECTORY | sed s/TRAJECTORY//g)
   frames=$(($LINES/$NATOMS))
   echo ""
   echo "I have read $frames frames"
   echo ""
#
######### MAIN LOOP 
#
  mkdir TRAJECTORIES 
  for ((i=1;i<$(($frames+1));i=$i+$step)) 
   do  
    mkdir TRAJ$i
    if [ ${control[1]} = 1 ]; then /bin/cp -R control.dyn ./TRAJ$i ; fi
    if [ ${control[2]} = 1 ]; then /bin/cp -R JOB_AD ./TRAJ$i ; fi
    if [ ${control[3]} = 1 ]; then /bin/cp -R job.cmd ./TRAJ$i ; fi
    if [ ${control[4]} = 1 ]; then /bin/cp -R Default.Route ./TRAJ$i/JOB_AD ; fi
# Positions:
    RX=($(head -n $CONT TRAJECTORY | tail -n $NATOMS |awk '{print $2}')) 
    RY=($(head -n $CONT TRAJECTORY | tail -n $NATOMS |awk '{print $3}')) 
    RZ=($(head -n $CONT TRAJECTORY | tail -n $NATOMS |awk '{print $4}')) 
# Velocities:
    VX=($(head -n $CONT TRAJECTORY | tail -n $NATOMS |awk '{print $5}')) 
    VY=($(head -n $CONT TRAJECTORY | tail -n $NATOMS |awk '{print $6}')) 
    VZ=($(head -n $CONT TRAJECTORY | tail -n $NATOMS |awk '{print $7}')) 
#
# header for GEOMETRY.xyz
    echo  $NATOMS >> ./TRAJ$i/GEOMETRY.xyz
    echo  "GEOMETRY step #$i" >> ./TRAJ$i/GEOMETRY.xyz
    convert=0.529177249
#
    for ((j=0;j<$NATOMS;j++)) 
     do 
        echo  ${s[$j]} ${Zatom[$j]} ${RX[$j]} ${RY[$j]} \
              ${RZ[$j]} ${mass[$j]} >> ./TRAJ$i/geom
        echo  ${VX[$j]} ${VY[$j]} ${VZ[$j]} >> ./TRAJ$i/veloc
#
        echo ${s[$j]} `echo "${RX[$j]}*$convert"|bc -l` \
              `echo "${RY[$j]}*$convert"|bc -l` \
              `echo "${RZ[$j]}*$convert"|bc -l` >> ./TRAJ$i/GEOMETRY.xyz
     done
#
    CONT=$(($CONT +  $(($step*$NATOMS))  ))
# some info 
    echo "TRAJ$i complete"
#
    mv TRAJ$i ./TRAJECTORIES
   done 
######### END OF MAIN LOOP ########
#
   good_end
#
exit 
