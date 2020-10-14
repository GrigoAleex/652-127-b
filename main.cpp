#include <iostream>
#include <cstring>

#define console_length 100

using namespace std;

int v[100];
int n;

int gauss( int n )
{
    return n*(n+1)/2;
}

int suma_progresie_artimetica( int n, int a1 )
{
    return n *( 2 * a1 + ( n - 1 ) * 3) / 2;
}

int n_impar( int n )
{
    return 3 * gauss( int( n / 2 ) ) + suma_progresie_artimetica( int( n / 2 ), int( n / 2 ) + 3);
}

int n_par( int n )
{
    return 3 * gauss( n / 2 - 1 ) + n / 2 + suma_progresie_artimetica( n / 2, n / 2 + 1 );
}


int rezolvare( int n )
{
    if ( n % 2 == 0 ) return n_par( n );
    return n_impar( n );
}

int m( int n )
{
    int m = 0;
    for( int i = 1; i <= n * 2; ++i )
    {
        if ( i % 2 == 0 ) v[ i - 1 ] = i;
        else v[ i - 1 ] = 2 * n - i;
        for( int j = 0; j < i - 1; ++j ) if( v[ j ] > v[ i - 1 ] ) m++;
    }
    return m;
}

bool test( int n )
{
    return m( n ) == rezolvare( n );
}

void break_line()
{
    cout << "\n";
}

int numar_cifre( int n )
{
    int  k = 1;
    while( n > 10 )
    {
        k++;
        n /= 10;
    }
    return k;
}

void print_permutare( int n )
{
    break_line();
    cout << "\tPermutarea este: \n";
    cout << "\t";
    for(int i = 1; i <= 2 * n; ++i)
    {
        for( int j = numar_cifre( i ); j <= numar_cifre( 2 * n ); ++j) cout << " ";
        cout << i << " ";
    }
    break_line();

    cout << "\t";
    for( int i = 1; i <= n * 2; ++i )
    {
        int target;
        if ( i % 2 == 0 ) target = i;
        else target = 2 * n - i;
        for( int j = numar_cifre( target ); j <= numar_cifre( 2 * n ); ++j) cout << " ";
        cout << target << " ";

    }
    break_line();
    break_line();
}

void start()
{
    for(int i = 0; i < console_length; i++)
        cout << "=";
    break_line();
    char s[] = "PROBLEMA 625/127 b)";
    int length = ( console_length - strlen(s) ) / 2;
    for(int i = 0; i < length ; i++) cout << " ";
    cout << s;
    break_line();
    for(int i = 0; i < console_length; i++) cout << "=";
    for( int i = 0; i < 3; i++ ) break_line();
    cout << "\tVa rugam sa introduceti un n pentru a calcula permutarea: ";
    cin >> n;
    print_permutare( n );
    cout << "\tNumarul inversiunilor pentru permutare este: " << rezolvare( n );
    for( int i = 0; i < 3; i++ ) break_line();
    for(int i = 0; i < console_length; i++) cout << "=";
}

int main()
{
    start();
}
