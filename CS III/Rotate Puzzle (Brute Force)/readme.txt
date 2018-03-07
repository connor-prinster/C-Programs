Inefficiencies:
* The main thing is that the searcb goes through a lot of stages. The highest I've seen is upwards of a million combinations.
* The more jumbles, the more complex (within reason). The more you shake up a board (without undoing any shuffling) the more 
  complicated it gets. We have pretty minor ones but it could easily get worse.

How I Would Improve: 
* To improve the algorithm, I would check the rows and columns individually to see if any of them contain all the numbers they
  are supposed to. For example, in Row 0, the correct row should have {1, 2, 3} and Column 0 would have {1, 4, 7}. The first 
  input has Rows 1 and 2 shifted by one. The current way of solving it takes 32 states when it really only should have taken 
  2 moves. The main reason for this is that the algorithm only checks to see if the board in its entirety is perfect, not its
  individual rows and columns. If the rows and columns were checked individually of one another, it has the potential to drop
  the amount of states to check by 33% or more depending on the number of rows/columns being perfect. It would be more 
  complicated to write, but it might drastically save time for more simple boards.