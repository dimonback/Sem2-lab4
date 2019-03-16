#include <cctype>
#include <iostream>
using namespace std;

class Alpha
{
private:
    unsigned bin;
public:
    Alpha() {bin=0;};
    Alpha(char*);
    Alpha operator *(Alpha& other);
    operator char*();
    friend ostream& operator <<(ostream&, Alpha& other);
};

Alpha::Alpha(char* s)
{
    bin=0;
    while(*s)
    {
        bin |= (1 << ('z' - tolower(*s)));
        s++;
    }
}

Alpha Alpha::operator*(Alpha& y)
{
    Alpha z;
    z.bin = bin & y.bin;
    return z;
}

ostream& operator << (ostream& out, Alpha& z)
{
    unsigned bit =1;
    int i;
    for(i=0; i<26; i++)
    {
        if((z.bin & bit)>0)
            out<<(char)('z'-i);
        bit=bit<<1;
    }
    return out;
}



int main(int argc, char * argv[])
{
    char tempstr1[32], tempstr2[32];
    //Alpha x(argv[1]);
    //Alpha y(argv[2]);
    Alpha z;
    Alpha x(tempstr1);
    Alpha y(tempstr2);
    cin >> tempstr1;
    cin >> tempstr2;
    z = x*y;
    cout << z <<endl;
    return 0;
}
