## cpmd2nx 
### A simple tool to convert a CPMD TRAJECTORY into NewtonX input folders.  
This tool reads a TRAJECTORY CPMD file and cuts it into TRAJ#'s folders ready to run NewtonX.
Source files are containded in /src:
- cpmd2nx.sh 
- functions.h
- include.h  

Short tests are provided in: 
- tests/ Folder including some tests. 

### INPUT
To run the code you need as input:
1. A TRAJECTORY (cpmd file),                                                                         
2. A "ramdom" GEOMETRY.xyz file of the species you want to study (this file, also from cpmd, is needed to know the correct atom order).                                                   
3. Additionally, you might also provide the usual control.dyn, job.cmd, Default.Route and JOB_AD files that will be copied in each of the TRAJ# folders.                                           

### OUTPUT                                                                                               
 The output is a bunch of TRAJ# folders containing geom, veloc and GEOMETRY.xyz files.                                
