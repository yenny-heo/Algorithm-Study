#include <iostream>
#include <math.h>
using namespace std;

double Answer;

int main(int argc, char** argv)
{
    int T, test_case;

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        int R, S, E, N;
        cin>>R>>S>>E>>N;
        int l, r, h;
        for(int i=0; i<N; i++){
            cin>>l>>r>>h;
            if(h>=R){
                Answer += h*2 - 4*R + M_PI*R;
            }else if(h<R){
                double cos = (double)(R-h)/R;
                double theta = acos(cos)/M_PI/2;
                Answer += 4*M_PI*R*theta - 2*sqrt(pow(R,2)-pow(R-h,2));
            }
        }
        Answer += E-S;
        
        cout << "Case #" << test_case+1 << endl;
        
        cout << fixed;
        cout.precision(8);
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
