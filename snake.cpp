#include <iostream>

using namespace std;

class Snake {

    private:

        class Node {

        /*Node class is declared inside the private section of the Snake class, so even though all of its data members
        are public, it will not be accessible outside the Snake class. */

        public: 

        int x, y;

        Node *next;

        Node() : x(0), y(0), next(0) {} // No-parameter constructor initializes data members to 0 and next pointer to NULL.

        Node (int x, int y){ //Parametered constructor initializes x & y positions
            
            this->x = x;

            this->y = y;

            next = NULL;

            cout << "test";
        }

        };

        Node *head, *tail;

    public:

        Snake () : head(0), tail(0) {} //Empty constructor initializes head and tail Node pointers to NULL.


        bool empty(){
            
            return head == NULL;
        }

        void enqueue(int& x, int& y){

            Node *newNode = new Node(x,y);

            if(empty()) {head = tail = newNode;}

            else {

                tail->next = newNode;

                tail = newNode;

            }

        }

        void dequeue(){

            if (empty()) {cerr << "Snake queue is empty. Cannot dequeue." << endl;}

            else{

                Node * ptr = head;

                head = head->next;

                delete ptr;

                if (empty()) {tail = NULL;}
                //If we don't do this, then tail would be pointing to the node memory location we just deleted (garbage memory).

            }
        }

        void front(int& x, int& y){

            if (empty()) {cerr << "Snake queue is empty. Cannot return front." << endl;}

            else{

                x = head->x;
                y = head->y;
            }
        }

};