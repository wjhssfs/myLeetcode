// 353. Design Snake Game

// Design a Snake game (https://en.wikipedia.org/wiki/Snake_(video_game)) that is played on a device with screen size = width x height. Play the game online (http://patorjk.com/games/snake/) if you are not familiar with the game. 

// The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

// You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

// Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

// When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

// Example:
// Given width = 3, height = 2, and food = [[1,2],[0,1]].

// Snake snake = new Snake(width, height, food);

// Initially the snake appears at position (0,0) and the food at (1,2).

// |S| | |
// | | |F|

// snake.move("R"); -> Returns 0

// | |S| |
// | | |F|

// snake.move("D"); -> Returns 0

// | | | |
// | |S|F|

// snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

// | |F| |
// | |S|S|

// snake.move("U"); -> Returns 1

// | |F|S|
// | | |S|

// snake.move("L"); -> Returns 2 (Snake eats the second food)

// | |S|S|
// | | |S|

// snake.move("U"); -> Returns -1 (Game over because snake collides with border)

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) :
    width(width), height(height), foodIndex(0)
    {
        swap(this->food, food);
        snake.emplace(0, 0);
        snakeSet.insert(getKey(snake.back()));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        //for (auto && p : snakeSet) {
        //    cout << p << endl;
        //}
        //cout <<"==="<< endl;
        pair<int, int> nextHead = snake.back();
        switch(direction[0]) {
            case 'U' : --nextHead.first; break;
            case 'D' : ++nextHead.first; break;
            case 'L' : --nextHead.second; break;
            case 'R' : ++nextHead.second; break;
        }
        if (nextHead.first < 0 || nextHead.first >= height || nextHead.second < 0 || nextHead.second >= width) return -1;
        if (foodIndex < food.size() && /*!snakeSet.count(getKey(food[foodIndex])) &&*/ nextHead == food[foodIndex]) {
            ++foodIndex;
        } else {
            snakeSet.erase(getKey(snake.front()));
            snake.pop();
        }

        if (snakeSet.count(getKey(nextHead))) return -1;
        snake.push(nextHead);
        snakeSet.insert(getKey(nextHead));
        return snake.size() - 1;
    }
private:
    string getKey(const pair<int, int> &p){
        return to_string(p.first) + "|" + to_string(p.second);
    }
    
    queue<pair<int, int>> snake;
    unordered_set<string> snakeSet;
    vector<pair<int, int>> food;
    int width, height, foodIndex;
    
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */