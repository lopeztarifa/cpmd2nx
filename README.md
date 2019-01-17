# cpmd2nx
########################################################################################################
#!/bin/bash                                                                                            #
########################################################################################################
# It reads a TRAJECTORY CPMD file and cuts it into TRAJ#'s folders ready to run NewtonX.               #
########################################################################################################
# Source files are: cpmd2nx.sh                                                                         #
#                   functions.h                                                                        #
#                   include.h                                                                          #
########################################################################################################
# INPUT                                                                                                # 
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
