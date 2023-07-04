# ATPG-GirlHackathon
The project aims to develop an algorithm for fault detection in combinational circuits. The code is written under the assumption that only one stuck at fault will be generated. It is inlfuenced from the D algorithm and uses a path tracking algorithm to test the faulty nodes and generate the test vector.

The circuit is stored in INPUT.txt file. You can change the contents of the cicruit in the same file

Pre-requisites: C++ compiler ( g++ [version: 6.3.0] ), make sure the path is added to the environment variables


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
make script
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
You will be prompted to provide the fault location and the type of fault (SA0 or SA1), after entering the required arguments press enter and the test pattern will be saved in Output.txt
