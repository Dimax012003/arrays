#include <iostream>
#include <vector>
using namespace std;
class stats{
 private:
	int row;
	int col;
	float **x;
 public:
    void get_array(){
    	cout<<"Enter number of the rows"<<endl;
    	cin>>row;
    	cout<<"Enter the number of the columnes"<<endl;
    	cin>>col;
	}
	void create_array(){//creates an array
		int i,j;
		x=new float*[row];
		 for(i=0;i<row;i++){
		 	x[i]=new float[col];
		 }
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				x[i][j]=(rand()%41)/4;
			}
		}
	}
	void show_array(){//shows the available array
		int i,j;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				cout<<x[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	float find_min(){
		int i,j;
		float min;
		min=x[0][0];
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(min>x[i][j]){
					min=x[i][j];
				}
			}
		}
		return min;
	}//returns the minimum element of the array
	float find_max(){
		int i,j;
		float max;
		max=x[0][0];
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(max<x[i][j])
				max=x[i][j];
			}
		}
		return max;
	}//returns the maximum element of the array
	void sort_row(){
		int i,j,k;
		float temp;
		for(i=0;i<row;i++){
			for(j=0;j<col-1;j++){
				for(k=j+1;k<col;k++){
					if(x[i][j]>x[i][k]){
					
				    temp=x[i][j];
				    x[i][j]=x[i][k];
				    x[i][k]=temp;	
					}
				}
			}
		}
	}//sorts the row of the array
	void sort_col(){
		int i,j,k;
		float temp;
		
			for(i=0;i<row-1;i++){
				for(k=i+1;k<row;k++){
					for(j=0;j<col;j++){
					
					if(x[k][j]<x[i][j]){
						temp=x[i][j];
						x[i][j]=x[k][j];
						x[k][j]=temp;
						}
					}
				}
			}
		
	}//sorts the columne of the array
	void show_pos(){
		int g,i,j,k=0;
		vector<int>yax;
		vector<int>xax;
		cout<<"Enter number in the array"<<endl;
		cin>>g;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				if(x[i][j]==g){
					yax.push_back(j);
					xax.push_back(i);
					k++;
				}
			}
		}
	  cout<<"Found in coordinates:"<<endl;
      for(i=0;i<yax.size();i++){
      	cout<<"y:"<<yax[i]+1<<" "<<"x:"<<xax[i]+1<<endl;
	  }
	}//returns the position of the element we want to search
	float sum(){
		int i,j;
		float sum1=0;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				sum1=sum1+x[i][j];
			}
		}
		return sum1;
	}
		//returns the sum of all the elements of an array
	int getcol(){
		return col;
	} 
	int getrow(){
		return row;
	}
	void multiply(vector<stats>v){
		int n,i,k,j;
		float **z;
		cout<<"Enter index:"<<endl;
		cin>>n;
		if(v[n].getrow()==col){
			z=new float*[row];
			for(i=0;i<row;i++){
				z[i]=new float[v[n].getcol()];
			}
			for(i=0;i<row;i++){
				for(j=0;j<v[n].getcol();j++){
					for(k=0;k<col;k++){
				     z[i][j]=z[i][j]+x[i][k]*v[n].returnelement(k,j);		
					}
				}
			}
		}
	  for(i=0;i<row;i++){
	  	for(j=0;j<v[n].getcol();j++){
	  		cout<<z[i][j]<<" ";
		  }
		  cout<<endl;
	  }
	}
	float returnelement(int i=0,int j=0){
	  return x[i][j];
	}
};
int main(){
	stats temp;
   	vector <stats> v;
   	int n,i;
   	float sum;
   	do{
   		cout<<endl;
   	cout<<"Choose"<<endl;
   	cout<<"1)Create an array"<<endl;
   	cout<<"2)Show arrays and stats"<<endl;
   	cout<<"3)Search a number in the array that added last"<<endl;
   	cout<<"4)Show the biggest sum"<<endl;
   	cout<<"5)Sort the array that added last "<<endl;
   	cout<<"6)Multiply last array added with an array created"<<endl;//multiplies the last array created with a previous array given by its index
   	cout<<"7)End program"<<endl;
   	cin>>n;
   	switch(n){
   		case 1:
   			temp.get_array();
   			temp.create_array();
   			v.push_back(temp);
   			system("cls");
   			break;
   		case 2:
   			for(i=0;i<v.size();i++){
   				v[i].show_array();
   				cout<<"Max->"<<v[i].find_max()<<endl;
   				cout<<"Min->"<<v[i].find_min()<<endl;
			   }
			   cout<<endl;
			   
			break;
		case 3:
			v[v.size()-1].show_pos();
			
			break;
		case 4:
			sum=v[0].sum();
			for(i=0;i<v.size();i++){
				if(v[i].sum()>sum){
					sum=v[i].sum();
				}
			}
			cout<<"Max sum->"<<sum;
			cout<<endl;
			
			break;
		case 5:
			v[v.size()-1].sort_col();
			v[v.size()-1].show_array();
			cout<<endl;
			cout<<endl;
			v[v.size()-1].sort_row();
			v[v.size()-1].show_array();
			
			break;
		case 6:
			v[v.size()-1].multiply(v);
			break;
		default :
			break;
		
	   }
	}while(n!=7);
	
}