#include <iostream>
#include <string>
using namespace std;

#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
using namespace itertools;


int main() {
	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	
	
	if (signal == 0) {
		cout<<"begining of test"<<endl;
		
		//-----------testcase- range------------//
		testcase.setname("range iterator check:");
		
		int t1=1;
		for( int i: range(1,10)){
			testcase.CHECK_EQUAL(i, t1);//
			t1++;
		}
		char t2='!';
		for(char c: range('!', '=')){
			testcase.CHECK_EQUAL(c, t2);
			t2++;
		}
		t2='5';
		for(char c:range('5','v')){
			testcase.CHECK_EQUAL(c, t2);
			t2++;
		}
		double t3=78.0;
		for(int i: range(78.0, 300.0)){
			testcase.CHECK_EQUAL(i, t3);
			t3++;
		}
		int t4=361;
		for( double i: range(361.0, 378.0)){
			testcase.CHECK_EQUAL(i, t4);
			t4++;
		}
		
		
		//------------testcase- chain-----------//
		testcase.setname("chain iterator check:");
		
		t1=1;
		for (int i: chain(range(1,7), range(7,15))){
			testcase.CHECK_EQUAL(i, t1);
			t1++;
		}
		t2='a';
		for(char a: chain(chain(range('a','f'), range('f','r')), range('r', 'z'))){
			testcase.CHECK_EQUAL(a, t2);
			t2++;
		}
		t3='1';
		for( auto a: chain(range('1', '5'), string("56789"))){
			testcase.CHECK_EQUAL(a, t3);
			t3++;
		}
		
		
		//-----------testcase- zip------------//
		testcase.setname("zip iterator check:");
		string s="1,a 2,b 3,c 4,d 5,e";
		
                for(auto i: zip(range(1,6), range('a', 'f')))
                testcase.CHECK_EQUAL(i, t1);

                s="1,5 2,6 3,7 4,8 5,9";
                for(auto i: zip(range(1,6), range(5,10)))
                testcase.CHECK_EQUAL(i, s[i]);

                s="e,5 f,6 g,7 h,8 i,9";
                for(auto i: zip(range('e', 'j'), range(5,10)))
                testcase.CHECK_EQUAL(i, s[i]);

                s="u,2 v,3 w,4 x,5 y,6";
                for(auto i: zip(range('v', 'z'), range(2,7)))
                testcase.CHECK_EQUAL(i, s[i]);

                s="a,f b,g c,h d,i e,j";
                for(auto i: zip(range('a', 'f'), string("fghij")))
                testcase.CHECK_EQUAL(i, s[i]);


                //-----------testcase- product------------//
                testcase.setname("product iterator check:");
                s="1,a 1,b 1,c 2,a 2,b 2,c 3,a 3,b 3,c";
		for(auto i: product(range(1,4), range('a', 'd')))
                testcase.CHECK_EQUAL(i, s[i]);

                s="3,6 3,7 3,8 4,6 4,7 4,8 5,6 5,7 5,8";
                for(auto i: product(range(3,6), range(6, 9)))
                testcase.CHECK_EQUAL(i, s[i]);

                s="c,w c,x c,y d,w d,x d,y e,w e,x e,y";
                for(auto i: product(string("cde"), range('w', 'z')))
                testcase.CHECK_EQUAL(i, s[i]);


                s="5,i 5,j 5,k 3,i 3,j 3,k 9,i 9,j 9,k";
                for(auto i: product(string("539"), range('i', 'l')))
                testcase.CHECK_EQUAL(i, s[i]);


                 //-----------testcase- powerset------------//
                testcase.setname("powerset iterator check:");
                s="{},{a},{b},{a,b},{c},{a,c},{b,c},{a,b,c}";

                 for(auto i: powerset(string("abc")))
                testcase.CHECK_EQUAL(i, s[i]);

                 for(auto i: powerset(range('a', 'd')))
                 testcase.CHECK_EQUAL(i, s[i]);




		grade = testcase.grade();
		
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

