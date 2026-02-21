#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next = nullptr ;
} ; // end studentNode

class LinkedList {
    protected :
        struct studentNode *start, **now ;
    public :

        LinkedList() {
            start = NULL ;
            now = &start ;
        }// end LinkdedList

        ~LinkedList() {} ;

        void InsNode( const char n[], int a, char s, float g ) {
            struct studentNode *newNode  = new studentNode ;
            strcpy( newNode->name , n ) ;
            newNode->age = a ;
            newNode->sex = s ;
            newNode->gpa = g ;

            newNode->next = *now ;
            *now = newNode ;
        }//end InsNode function

        void DelNode() {
            if (*now != NULL) {
                struct studentNode *temp = *now;
                *now = (*now)->next;
                delete temp;
            }// end if
        }// end DelNode

        void GoNext() {
            if ( *now != NULL ) {
                now = &((*now)->next);
            }// end if
        }//end GoNewx

        virtual void ShowNode() {
            printf( "%s %d %c %.2f\n" , (*now)->name , (*now)->age , (*now)->sex , (*now)->gpa ) ;
        }// end ShowNode
} ;// end LinkedList class

class NewList : public LinkedList {
public:
    void GoFirst() {
        now = &start;
    }// end GoFirst
    
    virtual void ShowNode() override {
        struct studentNode *temp = start;

        while (temp != NULL) {
            printf("%s ", temp->name );
            temp = temp->next;
        }// end while

        printf( "\n" ) ;
    }// end ShowNode functiion
}; // end NewList class

int main() {
    LinkedList listA ;
    NewList listB ;
    LinkedList *listC ;

    listA.InsNode( "one", 1, 'A', 1.1 ) ;
    listA.InsNode( "two", 2, 'B', 2.2 ) ;
    listA.InsNode( "three", 3, 'C', 3.3 ) ;
    listA.GoNext() ;
    listA.ShowNode() ;

    listB.InsNode( "four", 4, 'D', 4.4 ) ;
    listB.InsNode( "five", 5, 'E', 5.5 ) ;
    listB.InsNode( "six", 6, 'F', 6.6 ) ;
    listB.GoNext() ;
    listB.DelNode() ;
    listB.ShowNode() ;

    listC = &listA;
    listC->GoNext() ;
    listC->ShowNode() ;

    listC = &listB ;
    listC->ShowNode() ;

    return 0 ;
}// end main function