

# Hamming Code Implementation in C  

This repository contains a C program that demonstrates the generation and verification of **Hamming Codes**, which are used for error detection and correction in data transmission.

## Features  

- **Generation of Hamming Code**:  
  The program calculates the required parity bits and inserts them into the message to form the Hamming Code.  
- **Error Detection**:  
  Detects whether an error exists in the received message.  
- **Error Correction**:  
  (Feature can be added later) Helps identify and correct the bit error if present.  

## How It Works  

1. **Sender Side**:  
   - Accepts a binary message from the sender.  
   - Calculates the number of parity bits required.  
   - Generates the Hamming Code by inserting parity bits at appropriate positions.  

2. **Receiver Side**:  
   - Accepts the received message.  
   - Checks for errors using parity calculations.  
   - Reports if the received message is error-free or contains errors.  

## Input & Output  

- **Input**:  
  - Size of the message (up to 15,000 bits).  
  - Binary message from the sender.  
  - Received binary message.  

- **Output**:  
  - Original message.  
  - Hamming Code generated.  
  - Error detection result.  

## Example  

1. Enter the size of the message (e.g., 7 bits).  
2. Input the binary message: `1010101`.  
3. The program calculates the Hamming Code and displays it.  
4. Input the received message.  
5. The program checks for errors and displays the result.  

## Usage  

1. Clone the repository:  
   ```bash
   git clone https://github.com/utsavvachhani/HammingCode_C.git
   ```  

2. Compile the program:  
   ```bash
   gcc -o hamming_code hamming_code.c
   ```  

3. Run the program:  
   ```bash
   ./hamming_code
   ```  

4. Follow the interactive prompts for input.  

## About  

This program was created as part of my study of **Computer Networks** to understand error detection and correction using Hamming Codes.  
