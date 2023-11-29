#include <iostream>

using namespace std;

#include "snake.cpp";


int headx, heady;

int fruitx, fruity;

int x, y, score;

int height, width;

bool direction1, direction2;
//direction1 = 0 -> vertical / direction1 = 1 -> horizontal

// vertical direction2 = 0 -> right / vertical direction2 = 1 -> left

// horizontal direction2 = 0 -> up / horizontal direction2 = 1 -> down

Snake snake;


void grow();

void generate_fruit();

void move_head();

void change_direction(char dir);


int main(void){

snake.dequeue();

headx = 1, heady = 2;

snake.front(headx, heady);

snake.enqueue(headx, heady);

snake.enqueue(heady, headx);

cout << "X position of head is: " << snake.head->x <<  ' ' << ", Y position of head is: " << snake.head->y << endl;

cout << "X position of tail is: " << snake.tail->x << ' ' << ", Y position of tail is: " << snake.tail->y << endl;

snake.front(x, y);

cout << "X = " << x << ", Y = " << y << endl;

snake.dequeue();

cout << "X position of head is: " << snake.head->x << ' ' << ", Y position of head is: " << snake.head->y << endl;

cout << "X position of tail is: " << snake.tail->x << ' ' << ", Y position of tail is: " << snake.tail->y << endl;

snake.dequeue();

snake.dequeue();

}


void move_head(){

    snake.enqueue(headx, heady);

    if (direction1 == 0 && direction2 == 0)
		headx++;
	else if (direction1 == 0 && direction2 == 1)
		headx--;
	else if (direction1 == 1 && direction2 == 0)
		heady--;
	else if (direction1 == 1 && direction2 == 1)
		heady++;

	
	if (headx == fruitx && heady == fruity) {
		score++;
		grow();
		generate_fruit();
	}

    // Gameover conditions to be implemented

}

void generate_fruit(){

fruitx = rand() % width;

fruity = rand() % height;

// Specific dimensions to be implemented

}

void grow(){}

void change_direction(char dir){}