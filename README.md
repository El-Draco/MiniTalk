# **MiniTalk**
## A simple data communication program that uses UNIX signals in the form of a client and a server. On startup, the server prints the Process ID of the server which is then passed as an argument to the client application.
---
## In this project, messages are sent bit by bit using bitwise operators. Communication is done using SIGUSR1 and SIGUSR2 UNIX signals only.
>SIGUSR1 - for 1

>SIGUSR2 - for 0


## Messages are sent bit by bit, character by character and then later combined to form the final string (Supports all UNICODE characters including emojis).

## **Server initiation format**
```bash
./server
```

## The client takes two parameters:

* The server PID.
* The string to send.

## **Client initiation format:**
```bash
./client [process_ID] [string_to_send]
```

## Once the client sends a string, the server prints the message and also acknowldeges the message recieved by sending a signal back and printing a message on the client window.
