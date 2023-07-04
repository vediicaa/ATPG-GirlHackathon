# ATPG-GirlHackathon
The project aims to develop an algorithm for fault detection in combinational circuits. The code is written under the assumption that only one stuck at fault will be generated. It is inlfuenced from the D algorithm and uses a path tracking algorithm to test the faulty nodes and generate the test vector.

Make sure to have a g++ compiler for running the files

Clone the file in your local machine

```
git clone https://github.com/vediicaa/ATPG-GirlHackathon.git
```
navigate to the main directory:
```
cd ATPG-GirlHackathon
```
run the following command 

```
g++ -o script script.cpp
```
If there are no errors, the compilation is successful and an script.exe executable will be created, 

run (for windows):
```
script
```
run (for linux):

```
./script
```
You will be prompted to provide the fault location and the type of fault (SA0 or SA1), after entering the required arguments press enter and the test pattern will be saved in output.txt
