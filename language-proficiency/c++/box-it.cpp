#include <bits/stdc++.h>

class Box{

    long long length, breadth, height;

    public:

        Box(){
            length = breadth = height = 0;
        }

        Box(int l, int b, int h){
            length = l;
            breadth = b;
            height = h;
        }

        Box(Box &box){
            length = box.getLength();
            breadth = box.getBreadth();
            height = box.getHeight();
        }

        int getLength(){
            return length;
        }

        int getBreadth(){
            return breadth;
        }

        int getHeight(){
            return height;
        }

        long long CalculateVolume(){
            return length * height * breadth;
        }

        bool operator<(Box &b){
            if(length != b.getLength())
                return (length < b.getLength());
            
            if(breadth != b.getBreadth())
                return (breadth < b.getBreadth());

            return (height < b.getHeight());
        }

};

ostream& operator<<(ostream& out, Box &b){
    out << b.getLength() << " " << b.getBreadth() << " " << b.getHeight();
    return out;
}

using namespace std;
void check2(){
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main(){
	check2();
}