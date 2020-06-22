#include<bits/stdc++.h>

using namespace std;

class Box
{
    private:

        int l;
        int b;
        int h;

    public:

        // CONSTRUCTORS
        Box() // Default Constructor
        {
            l = 0;
            b = 0;
            h = 0;
        }

        Box(int le, int br, int he)
        {
            setLength(le);
            setBreadth(br);
            setHeight(he);
        }

        Box (const Box& box2) // Copy Constructor
        {
            l = box2.l;
            b = box2.b;
            h = box2.h;
        }

        // ACCESSORS - GETTERS
        int getLength()
        {
            return l;
        }

        int getBreadth()
        {
            return b;
        }

        int getHeight()
        {
            return h;
        }

        // MUTATORS - SETTERS
        void setLength(int le)
        {
            l = le;
        }

        void setBreadth(int br)
        {
            b = br;
        }

        void setHeight(int he)
        {
            h = he;
        }

        // METHODS
        long long CalculateVolume()
        {
            return ((long long)l * b * h);
        }
        
    // Allowing overloading to access private data
    friend bool     operator<   (const Box& A, const Box& B); 
    friend ostream& operator<<  (ostream& out, const Box& B);

};

// OVERLOADING
bool operator<(const Box& A, const Box& B) 
{
    if((A.l < B.l)
    || (A.b < B.b) && (A.l == B.l)
    || (A.h < B.h) && (A.b == B.h) && (A.l == B.l))
    {
        return true;
    }
    else
    {
        return false;
    }            
};

ostream& operator<< (ostream& out, const Box& B)
{
    out << B.l << " " << B.b << " " << B.h;

    return out;
};

