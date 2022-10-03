# unreal-doors-CMyers79513
<img width="905" alt="Screenshot 2022-08-20 163438" src="https://user-images.githubusercontent.com/109536729/185769973-5dc13e22-e016-4f3c-a4ad-7138bd22ea19.png">
This is a screenshot of my map layout so far. The 'maze' is guessing which door is the correct door to go through for each row.
Four of the doors in each row will reset you to the beginning of the map and one door will allow you to continue to the next row.

<img width="902" alt="Screenshot 2022-08-20 163601" src="https://user-images.githubusercontent.com/109536729/185770093-3ddba650-f7f4-47f7-916a-b365a9ed24ef.png">
Another door type in the map is this timed door. The door will slowly descend over time as you are completing the maze.

<img width="805" alt="Screenshot 2022-08-20 191406" src="https://user-images.githubusercontent.com/109536729/185770174-11aa5d1c-cd8c-48f3-b92f-a9c8f993fb3b.png">
<img width="799" alt="Screenshot 2022-08-20 191427" src="https://user-images.githubusercontent.com/109536729/185770185-68e2335b-572b-4f34-acdf-057a056fec45.png">
If the door fully descends into its frame, you have failed the map and must exit the maze to restart.

<img width="796" alt="Screenshot 2022-08-20 191745" src="https://user-images.githubusercontent.com/109536729/185770232-2c91f5ad-1d7b-43d0-a095-1e06ff5fb6fc.png">
<img width="802" alt="Screenshot 2022-08-20 191810" src="https://user-images.githubusercontent.com/109536729/185770234-6d44d320-ab9b-4b5a-85dd-444710f64fe8.png">
<img width="805" alt="Screenshot 2022-08-20 191833" src="https://user-images.githubusercontent.com/109536729/185770237-1e3ae2ba-1425-413a-a34b-e52c86a500b0.png">
<img width="802" alt="Screenshot 2022-08-20 191855" src="https://user-images.githubusercontent.com/109536729/185770240-7d887fd2-8d6a-4f57-8819-1294fe1cb9cc.png">
This is my third door type. A regular opening and closing door. The door opens from both sides and stays open until you are out of its range.

## Module 7 Update
<img width="526" alt="Screenshot 2022-08-27 192405" src="https://user-images.githubusercontent.com/109536729/187089864-3f108552-f4cc-4377-b1d2-664e4a4b4526.png">
<img width="454" alt="Screenshot 2022-08-27 192435" src="https://user-images.githubusercontent.com/109536729/187089871-c92275c3-5315-4164-8262-fb0f6af6136a.png">
I made a character blueprint class. I implemented a jump dash mechanic. If the character is sprinting, they will jump but also be launched forward to cover large distances. 




Normal jump:




https://user-images.githubusercontent.com/109536729/187090177-ade9f71f-6116-43ff-a0f7-26d6a37a34a2.mp4




Double Jump: 


https://user-images.githubusercontent.com/109536729/187090327-1769e248-aa96-46f5-8774-b9b03ab86160.mp4





Jump Dash:




https://user-images.githubusercontent.com/109536729/187090348-4736b1fa-42e2-431c-91ed-f339c66e8f18.mp4




I also used a random sequence player for the character to have multiple idle animations so it looks more interesting.



https://user-images.githubusercontent.com/109536729/187090458-7b85e7a1-4e2c-4068-ab92-1e24f1f756a5.mp4






Here is my animation blueprint


<img width="552" alt="Screenshot 2022-08-28 140708" src="https://user-images.githubusercontent.com/109536729/187090538-1319b93f-1fa0-49ec-b58e-85a5098b00b2.png">



I split the existing jump animation into a beginning, middle, and end. It seems to make shorter or longer jumps look better. 







https://user-images.githubusercontent.com/109536729/187090764-e75e07bb-752d-4d46-abd9-9ba6f3fae851.mp4

## Final Update
The final update of this project focused on designing throwable bombs and defining their behaivor.


The throwable blueprint that all of the bombs inherit from.


<img width="719" alt="Screenshot 2022-10-02 225221" src="https://user-images.githubusercontent.com/109536729/193498622-62be502b-7913-478e-a5a9-8896b18e2644.png">



The first bomb type is a normal bomb. The bomb is dropped at the player's feet and is rolled in the direction that the player is facing.



https://user-images.githubusercontent.com/109536729/193499280-eb84bf48-c954-4d01-904c-18e3a597b7fc.mp4




The second bomb type is a longbow bomb. The bomb travels in a straight line in the direction the player is aiming the camera. The damage scales with distance traveled.




https://user-images.githubusercontent.com/109536729/193499456-8b02a398-7497-411d-883f-850581f95014.mp4




The final bomb type is a lobbed bomb. The bomb is 'lobbed' in the air based on where the player is aiming the camera. The size and damage of the bomb scales with time in the air before hitting something.





https://user-images.githubusercontent.com/109536729/193499794-ba0b685f-e102-4296-8253-99076e646159.mp4

