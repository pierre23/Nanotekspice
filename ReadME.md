# **Nanotekspaice**
####  CPP module {EPITECH}
###### Electonic chipset emulator

[![](https://www.hidglobal.com/sites/default/files/chipset.png)]

Nanotekspice is a chipset emulator. We can use it to test electric circuit.

### **Tech**
For this project we've used the following:
  - CPP language  

### **Compilation & execution**

> You have to compile nanotekSpice with the "Make" command

```sh
$ Make
$ ./nanotekspice [circuitPath].nts [pinName1]=[value] [pinName2]=[value] ...

```
You can create your own circuit by format a .nts like that :

.chipsets:
clock a
input b
output s
4001 porte
.links:
a:1 porte:1
b:1 porte:2
porte:3 s:1


After the .chipset you declare all chipsets you want to use, and after the .links you declare the links between chipset's pins.


[![](http://anatole-menichetti.fr/wp-content/uploads/2015/09/epitech1.png)]
