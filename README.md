## Tic tac toe AI using minimax with alpha beta pruning




### Known issues:
**Behaviour**
- Code cleanliness
- The algorithm doesn't consider depth of desired outcome -> meaning it doesn't go for the 'fastest' win
- The algorithm is currently only implemented for 'O' (user plays as 'O')
- barebone error handling (throws instead of re-prompting)

**Code quality**
- `Game` is copied by value throughout the search
- Lacks a cleaner `game` implementation, everything is bound to the `game`-class. Would be better to have separate type for gamestate and have the a static game utils class with static functions that alter the gamestate object and 
- Repetition, too few helper functions and magic numbers hurt readability.
- Inconsistent naming and formatting (camelCase variables next to snake_case functions).


## How to test 
1. Clone repository
```bash
git clone https://github.com/livercomba/Minimax-tic-tac-toe
```
2. Navigate to project directory
```bash
cd Minimax-tic-tac-toe
```
3. Compile (using g++ for example )
```bash
g++ -std=c++17 -o tictactoe *.cpp
```
