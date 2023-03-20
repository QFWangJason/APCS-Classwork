#This is the word game
#Declare 3 word lists for different levels
#Create a menu and menu input function
#For the playgame, randomly select a word from the list, then throw into the play function
#Turns = 7-Difficulty level + length of word
#Play function handles the guesses, store guessed letters in a list, then use it as a comparison to the word, print letters if guessed and _ if not
#Score = 5*Difficulty level + Remaining turns*Difficulty level
#Open a Leaderboard txt file and store two lists in it, one for score and one for name, then read and sort the score list and print out the top 5 using a for loop
#restart the game unless exit is selected
import os, random
os.system('clear')
##Lists
Easy = ["gold","lot","can","table","soft","slice","fail","lemon","fight","relax","neck","bland","wake","door","obese"]
Normal = ["looting","endure","avenue","channel","tradition","crusade","guerrilla","feedback","empirical","judicial","captivate","texture","evaluate","catalogue","password"]
Hard = ["extraterrestrial","acquisition","deteriorate","confrontation","cooperative","continental","representative","contribution","calculation","sensitivity","fashionable","observation","incongruous","concentration","information"]
word=""
guess=""
rep = True #Repeat the game
def wordselect(choice): #The function that handles menu input
    global word
    if '1' in choice:
        word=random.choice(Easy)
    elif '2' in choice:
        word=random.choice(Normal)
    elif '3' in choice:
        word=random.choice(Hard)
def Menu(): #Menu GUI
    os.system('clear') #Clear Terminal
    print("----------------")
    print("|Word game     |")
    print("|1.Play Easy   |")
    print("|2.Play Normal |")
    print("|3.Play Hard   |")
    print("|4.Instructions|")
    print("|5.Exit        |")
    print("----------------")
    choice = input("Enter number:") #store choice
    global mp
    mp = choice
    os.system('clear')
    if '4' in choice:
        print("choose difficulty. The more difficult the less chances you'll get, but more points") #Instructions
    elif '5' in choice:
        print ("Good Bye")
        exit()
    elif '1' in choice or '2' in choice or '3' in choice:
        wordselect(choice)
    else:
        print("Please input a valid number")
        Menu()
def getLetter(): #Gets the input letter per attempt
    global guess
    check = True
    while check:
        try:
            guess = input("\nenter a letter to guess: ")
            if guess.isalpha() and len(guess) == 1:
                guess=guess.lower()
                check=False
            else:
                print("only one letter at a time")
        except ValueError:
            print("only one letter at a time")

def leaderboard(): #Creates and reads a txt file and prints out the scoreboard
    file = open("Leaderboard.txt", 'a')
    file.write((str(score)) + "       " + (name) + "\n")
    file.close()
    file = open("Leaderboard.txt", 'r')
    readthefile = file.readlines()
    sortedData = sorted(readthefile, reverse = True)
    print("==============================")
    print("    Top 5 Winning Scores")
    print("Pos        " + "Score     " + " Name")
    try:
        for line in range(5):
            print(" " + str(line + 1) + "\t    " + str(sortedData[line]))
    except IndexError:
        print("Not enough games played for a scoreboard, must be at least 5")

def playing(): #Loop for guessing the word while there are still turns left
    turns=len(word)+(7-int(mp))
    check = True
    guesses=''
    count=0
    while(turns>0 and check):
        for letter in word:
            if letter in guesses:
                print(letter, end=" ")
                if len (guesses)>=len(set(word))-1:
                    check = False
            else:
                print("_", end=" ")
        getLetter()
        if guess in word:
            if guess not in guesses:
                guesses += guess
                print(" Good guess ") #For correct guesses
            else:
                print("You have used that letter before")
        else:
            turns -=1
            print("wrong letter, try again")
        print(guesses)
    if(not check):
        global score
        score = 5*int(mp)+turns*int(mp)
        print(int(mp))
        print("you guessed correctly, your score was",score)
        global name
        name = input("your username: ") #Gets the player name
        leaderboard() #Redirects to the leaderboard function
    else:
        print("Sorry you did not guess correctly...") #Game over
    input("Press enter to countinue")
while rep:
    Menu()
    print(word) #For Debugging
    playing()

