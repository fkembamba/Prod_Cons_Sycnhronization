# Producer consumer Problem

This project is about producer consumer problem solution. It provides the synchronization solution of 
procucer and consumer. the consumer must consume only if there is items produced.
The producer must wait the consumer to consume the products before he/she produces

## The purpose 
The purpose of this project is to avoid both producer and consumer to acces critical section at the same time

## Getting Started

Our project considers Mom and Dady as mom the producer and Dady the consumer
The product is Milk
The shared memory is fridge

### Expected output 

- Mom comes home.
- Mom checks the fridge.
If there is no milk  then..
- Mom goes to buy milk...
- Mom puts milk 1 in the fridge
- Mom puts milk 2 in the fridge
- Mom close the fridge and leaves.

#### if your run producer again this will happen

- Mom comes home.
- Mom checks the fridge.
- Mom closes the fridge and leaves.

### Dependencies
For the project to run is linux operating system
We used semaphore to protect critical section
and we used shared memory as a global variable that both producer and consumer can access when they 
have right to access.

### Running our program
* You need linux
* Download codes from github and run

### Executing program

#### Run the following codes
gcc producer.c -pthread -lrt -o producer
gcc consumer.c -pthread -lrt -o consumer

The command above generates executable files producer and consumer
Run the files as follow
#### *./producer
#### *./consumer

####or ./producer & ./consumer & to run the both concurently
    

## Authors

#### Fred Kembamba

Initial Release
1.0

### Inspiration, code snippets

Too much milk
I modified the codes to fit producer consumer scenario. The codes both dad and mom are consumer and producer

