/* 
TODO:
- make a menu
@parameter
*/

#ifndef SNAKE_CPP
#define SNAKE_CPP
/* #pragma once */
    
    #include <ctime>
#include <string>
    #include <vector>
    #include <cstddef>
    #include <cstdlib>
    #include <unistd.h>
    #include <ncurses.h>
    
    struct
        SnakePart
        {
            
            int
                x , y
            ;
            
            SnakePart
                ( int col , int row )
            ;
            
            SnakePart
                ( )
            ;
            
        }
    ;
    
    class
        SnakeClass
        {
            
          private:
            int
                points , del ,
                maxWidth , maxHeight
            ;
            
            std::string
                partChar
            ;
            
            char
                direction ,
                oldalChar ,
                food
            ;
            
            bool
                get
            ;
            
            SnakePart Food;
            
            std::vector <SnakePart>
                snake
            ;
            
            void
                putFood
                ( void )
            ;
            
            bool
                collision
                ( void )
            ;
            
            void
                moveSnake
                ( void )
            ;
            
          public:
            SnakeClass
                ( )
            ;
            
            ~SnakeClass
                ( )
            ;
            
            void
                start
                ( void )
            ;
            
        }
    ;
    
#endif /* SNAKE_CPP */

SnakePart::SnakePart
    ( int col , int row )
{
    
    x =
        col
    ;
    
    y =
        row
    ;
    
}

SnakePart::SnakePart
    ( )
{
    
    x =
        0
    ;
    
    y =
        0
    ;
    
}

SnakeClass::SnakeClass
    (  )
{
    
    initscr
        ( )
    ;
        
        nodelay /* getch ( ) wont wait for user keypress! */
            ( stdscr , true )
        ;
        
        keypad
            ( stdscr , true )
        ;
        
        noecho
            ( )
        ;
        
        curs_set
            ( 0 )
        ;
        
        getmaxyx
            ( stdscr , maxHeight , maxWidth )
        ;
        
        /* initialize a few variables! */
        
        partChar =
            "<#>"
        ;
        
        oldalChar =
            ( char ) 219
        ;
        
        food =
            '*'
        ;
        
        Food.x =
            0
        ;
        
        Food.y =
            0
        ;
        
        for
            ( size_t i { }; i < 5; ++i )
        {
            
            snake.push_back
                ( SnakePart ( 40 + i , 10 ) )
            ;
            
        }
        
        points =
            0
        ;
        
        del =
            110000
        ;
        
        get =
            false
        ;
        
        direction =
            'l'
        ;
        
        srand
            ( time ( 0 ) )
        ;
        
        putFood
            ( )
        ;
        
        for
            ( size_t i { }; i < maxWidth - 1; ++i )
        {
            
            move
                ( 0 , i )
            ;
            
            addch
                ( oldalChar )
            ;
            
        }
        
        for
            ( size_t i { }; i < maxWidth - 1; ++i )
        {
            
            move
                ( maxHeight - 2 , i )
            ;
            
            addch
                ( oldalChar )
            ;
            
        }
        
        for
            ( size_t i { }; i < maxHeight - 1; ++i )
        {
            
            move
                ( i , 0 )
            ;
            
            addch
                ( oldalChar )
            ;
            
        }
        
        for
            ( size_t i { }; i < maxHeight - 1; ++i )
        {
            
            move
                ( i , maxWidth - 2 )
            ;
            
            addch
                ( oldalChar )
            ;
            
        }
        
        move
            ( maxHeight - 1 , 0 )
        ;
        
        for
            ( size_t i { }; i < snake.size ( ); ++i )
        {
            
            move
                ( snake [ i ].y , snake [ i ].x )
            ;
            
            addstr
                ( partChar.c_str ( ) )
            ;
            
            refresh
                ( )
            ;
            
        }
        
        move
            ( maxHeight - 1 , 0 )
        ;
        
        printw
            ( "%d" , points )
        ;
        
        move
            ( Food.y , Food.x )
        ;
        
        addch
            ( food )
        ;
        
        refresh
            ( )
        ;
        
    // endwin
    //     ( )
    // ;
    
}

SnakeClass::~SnakeClass
    ( )
{
    
    nodelay
        ( stdscr , false )
    ;
    
    getch
        ( )
    ;
    
    endwin
        ( )
    ;
    
}

void
    SnakeClass::putFood
    ( )
{
    
    while
        ( true )
    {
        
        int
            tmpX =
            rand ( ) % maxWidth + 1
        ;
        
        int
            tmpY =
            rand ( ) % maxHeight + 1
        ;
        
        for
            ( size_t i { }; i < snake.size ( ); ++i )
            if
                ( snake [ i ].x == tmpX && snake [ i ].y == tmpY )
                continue;
        if
            ( tmpX >= maxWidth - 2 || tmpY >= maxHeight - 3 )
            continue;
        Food.x = tmpX;
        Food.y = tmpY;
        
        break;
        
    }
    
    move
        ( Food.y , Food.x )
    ;
    
    addch
        ( food )
    ;
    
    refresh
        ( )
    ;
    
}

bool
    SnakeClass::collision
    ( )
{
    
    if
        ( snake [ 0 ].x == 0 || snake [ 0 ].x == maxWidth - 2 || snake [ 0 ].y == 0 || snake [ 0 ].y == maxHeight - 3  )
        return true;
    for
        ( size_t i { 2 }; i < snake.size ( ); ++i )
        if
            ( snake [ 0 ].x == snake [ i ].x && snake [ i ].y == snake [ 0 ].y )
            return true;
    if
        ( snake [ 0 ].x == Food.x && snake [ 0 ].y == Food.y )
    {
        
        get =
            true
        ;
        
        putFood
            ( )
        ;
        
        points +=
            10
        ;
        
        move
            ( maxHeight - 1 , 0 )
        ;
        
        printw
            ( "%d" , points )
        ;
        
        if ( (points % 100) == 0 )
            del
                -= 10000
            ;
        
    }
    
    else
        get =
            false
        ;
    
    return false;
    
}

void
    SnakeClass::moveSnake
    ( )
{
    
    int tmp =
        getch
        ( )
    ;
    
    switch
        ( tmp )
    {
        
        case
            KEY_LEFT:
            if
                ( direction != 'r' )
                direction = 'l';
            break
        ;
        
        case
            KEY_UP:
            if
                ( direction != 'd' )
                direction = 'u';
            break
        ;
        
        case
            KEY_DOWN:
            if
                ( direction != 'u' )
                direction = 'd';
            break
        ;
        
        case
            KEY_RIGHT:
            if
                ( direction != 'l' )
                direction = 'r';
            break
        ;
        
        case
            KEY_BACKSPACE:
                direction = 'q';
            break
        ;
        
    }
    
    if
        ( !get )
    {
        
        move
            ( snake [ snake.size ( ) - 1 ].y , snake [ snake.size ( ) - 1 ].x )
        ;
        
        addch
            ( ' ' )
        ;
        
        refresh
            ( )
        ;
        
        snake.pop_back
            ( )
        ;
        
    }
    
    if
        ( direction == 'l' )
        snake.insert
            (
                snake.begin ( ) ,
                SnakePart
                (
                    snake [ 0 ].x - 1 ,
                    snake [ 0 ].y
                )
            )
        ;
    
    else if
        ( direction == 'r' )
        snake.insert
            (
                snake.begin ( ) ,
                SnakePart
                (
                    snake [ 0 ].x + 1 ,
                    snake [ 0 ].y
                )
            )
        ;
    
    else if
        ( direction == 'u' )
        snake.insert
            (
                snake.begin ( ) ,
                SnakePart
                (
                    snake [ 0 ].x ,
                    snake [ 0 ].y - 1
                )
            )
        ;
    
    else if
        ( direction == 'd' )
        snake.insert
            (
                snake.begin ( ) ,
                SnakePart
                (
                    snake [ 0 ].x ,
                    snake [ 0 ].y + 1
                )
            )
        ;
    
    move
        ( snake [ 0 ].y , snake [ 0 ].x )
    ;
    
    addstr
        ( partChar.c_str ( ) )
    ;
    
    refresh
        ( )
    ;
    
}

void
    SnakeClass::start
    ( )
{
    
    while
        ( true )
    {
        
        if ( collision ( ) )
        {
            
            // Get the current terminal dimensions
            int
                centerY , centerX
            ;
            
            getmaxyx
                ( stdscr , centerY , centerX )
            ; // Get height and width

            // Calculate the position to center the message
            int messageY =
                centerY / 2
            ; // Center vertically
            
            int messageX =
                ( centerX - 10 ) / 2
            ; // Center horizontally (10 is the length of "Game Over!")

            move(messageY, messageX); // Move to the calculated position
            
            printw
                ( "Game Over!" )
            ;
            
            break;
            
        }
        
        moveSnake
            ( )
        ;
        
        if
            ( direction == 'q' )
            break;
        
        usleep
            ( del )
        ;
        
    }
    
}

int
    main
    ( void )
{
    
    SnakeClass s;
    s.start
        ( )
    ;
    
}
