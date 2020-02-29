# Zork

C++ Test - Simple Zork Game Assignment

## Getting Started

The objective's game is to escape from the dungeon by recolecting the items and defeating your enemy.

### Moving between Rooms

------------

For moving between rooms (considering that the door is open), you are not allowed to move into another room unless the door is open.

Command: "move " + direction

I.E move north , move east , move south , move west.

### Opening doors

------------

Initially all the doors are closed and doesn't a key except for the door in the room 2 on the east direction ( this door needs the key  ).

For unlocking the door is automatically detected when you have the key and try to open the door.

Command: "open " + direction + " door"

I.E open north door.

### Picking up items

------------

Items can be picked up.

For picking sword and key items the player must have a bag. They automatically will be saved inside the bag.
    
Command: "pick " + item

I.E pick letter, pick sword , pick bag.

### Toss/Drop items

------------

Items can be tossed/dropped.

For tossing/dropping sword and key items, they automatically will be taken out of the bag and dropped into the room.

Command: "toss " + item

I.E toss letter, toss sword, toss bag.

### Read items

------------

Items can be read.

Only items such as letter or note could be read

Command: "read " + item

I.E read letter, read note.

### Attack

------------

The player can attack only if it is in the room of the enemy and is alive.

In this mode the attack will depend of the success rate that the item has.

Enemy will attack also.

It is recommended to have a sword, but you can attack with other items but will not harm the enemy

Command: "attack " + name of the enemy +  " using " + item

I.E attack monster using sword, attack monster using key.

### Command not found

------------

It the command not exists then it will display a message

## Solution

The solution can be found in

```
Zork/Solution.txt
```

## Test

A  test can be found in

```
Zork/ExhaustiveTest.txt
```
## Deploy
The executable can be found at
```
Zork/Zork.exe
```
## Contributing

Please read [CONTRIBUTING.md](https://bitbucket.com/saulzini) for details on our code of conduct, and the process for submitting pull requests to us.


## Authors

* **Saul Juarez** 

See also the list of [contributors](https://github.com/saulzini/zork/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
