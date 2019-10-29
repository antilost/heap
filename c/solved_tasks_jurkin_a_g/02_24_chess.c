/*
 * Input positions for black king and 3 white rooks (castles).
 * Validate coordinates entered.
 * Find if black king is threatened by some of the rooks.
 */
#include <stdio.h>

struct ChessPos
{
    char x;
    int y;
};

const int CASTLES_COUNT = 3;

int check_chess_piece_position(struct ChessPos chess_piece);
void explain_validation_error(int error_code);

int main()
{
    int i, j;
    struct ChessPos white_rooks[CASTLES_COUNT];
    struct ChessPos black_king;

    // Data input
    printf("Enter black king position (e.g., d7): ");
    scanf("%1s,%d", &black_king.x, &black_king.y );
    //getchar();

    printf("black_king: '%c', '%d'\n", black_king.x, black_king.y);

    int error_code = check_chess_piece_position(black_king);
    if (error_code)
    {
        explain_validation_error(error_code);
        return 1;
    }

    for (i = 0; i < CASTLES_COUNT; i++)
    {
        printf("Enter rook #%d position: ", i);
        scanf("%1s,%d", &( white_rooks[i].x ), &( white_rooks[i].y ) );
        printf("white_rooks #%d: '%c', '%d'\n", i, white_rooks[i].x, white_rooks[i].y);

        //getchar();
        //fflush(stdin);

        error_code = check_chess_piece_position(white_rooks[i]);
        if (error_code)
        {
            explain_validation_error(error_code);
            return 1;
        }

        //printf("Castle #%d position is %c and %d\n", i, white_rooks[i].x, white_rooks[i].y);
    }

    // Validate chess pieces positions
    for (i = 0; i < CASTLES_COUNT; i++)
    {
        for (j = i + 1; j < CASTLES_COUNT; j++)
        {
            if ( (white_rooks[i].x == white_rooks[j].x) && (white_rooks[i].y == white_rooks[j].y) )
            {
                printf("Castles #%d and #%d have the same positions!\n", i, j);
                return 1;
            }
            
        }

        if ( (white_rooks[i].x == black_king.x) && (white_rooks[i].y == black_king.y) )
        {
            printf("Castle #%d and the black king have the same positions!\n", i);
            return 1;
        }
    }

    // Check king threats
    for (i = 0; i < CASTLES_COUNT; i++)
    {
        if ( (white_rooks[i].x == black_king.x) || (white_rooks[i].y == black_king.y) )
        {
            printf("Black king is threatened by rook #%d!\n", i);
        }
    }

    getchar();

    return 0;
}

int check_chess_piece_position(struct ChessPos chess_piece)
{
    if ( !( ('a' <= chess_piece.x) && (chess_piece.x <= 'h') ) )
        return -1;

    if ( !( (1 <= chess_piece.y) && (chess_piece.y <= 8) ) )
        return -2;

    return 0;
}

void explain_validation_error(int error_code)
{
    switch(error_code)
    {
        case -1:
        {
            printf("Chess piece X coordinate should be in range 'a'..'h'\n");
            break;
        }
        case -2:
        {
            printf("Chess piece Y coordinate should be in range 1..8\n");
            break;
        }
        default:
            printf("Chess piece coordinate is incorrect (unknown error)\n");
    }
}
