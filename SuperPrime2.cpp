//��ҵ���������������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
class SuperPrime {
  public:
  	SuperPrime():number(0) {  //Ϊʲô�����У� 
  	  size = 0;
  	}
  	SuperPrime(int n):number(n) {
  	  size = 0;
  	  split();  //�����ǹ������ 
	}
  	~SuperPrime() {
  	  for (int i = 0; i < size; ++i)  //���ٶ��� 
		delete N[i]; 
	}
  	bool isSuperPrime() {
  	  SuperPrime a(sum());   //����ͨ����ת��Ϊ���� 
	  SuperPrime b(multi());
	  SuperPrime c(squareSum());
	  if (isPrime() && a.isPrime() && b.isPrime() && c.isPrime())
	    return true; 
  	  return false;
	}
  private:
  	const int number;
  	SuperPrime *N[100];
	int size;
  	bool isPrime() { 
  	  //2��number-1������ 
  	  return false;
	}
	void split() {   //�����������ģʽ 
	  // number split into N
	  int temp = number;
	  while(temp > 0) {
	  	int n = temp % 10;
	  	temp /= 10;
	  	N[size] = new SuperPrime(n);   //������� 
	  	size += 1;
	  } 
	}
	int sum() {
        int sum;
        for (int i = 0; i <= size; i++) {
            sum += N[i];
        }
	  return sum;
	}
	int multi() {
        int multi;
        for (int i = 0; i <= size; i++) {
            multi += N[i]*N[i];
        }
        return multi;
	  return 0;
	}
	int squareSum() {
        int squareSum;
        for (int i = 0; i <= size; i++) {
            squareSum += N[i]*N[i]*N[i];
        }
        return squareSum;
	  return 0;
	}
};
class Set {
  public:
  	Set(int from, int to) {
  	  size = 0;
	}
  	~Set() {
	}
  	int count() {
  	  int count = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      count += 1;
	  return count; 
	}
  	int sum() {
  	  int sum = 0;
  	  for (int i = 0; i < size; i++)
  	    if(set[i].isSuperPrime())
  	      sum += set[i];
	  return sum; 
	}
  private:
  	SuperPrime set[1000];
  	int size;
};
int main() {
    Set sp(100, 999);
  SuperPrime sp(100,999);
   std::cout << sp.count << std::endl;
    std::cout << sp.sum << std::endl;
  return 0;
}
