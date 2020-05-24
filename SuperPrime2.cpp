//作业：删除多余的集合类，使用继承方法实现相同的功能。 

#include <iostream>

class Prime {

public:

    Prime() :number(0) {

    }

    Prime(int n) :number(n) {

    }

    ~Prime() {

    }

    virtual bool isPrime() {

        //2到number-1的因子

        std::cout << "Prime's isPrime() call" << " " << this->number << std::endl;

        int i;

        for (i = 2; i < number; i++) {

            if (number % i == 0)    break;

        }

        if (i != number) return false;

        return true;

    }

    const int number;



};

class PrimeSet {

public:

    PrimeSet(int size) {

        //集合的构造什么？

        set = new Prime * [size];

        this->size = size;

        index = 0;

    }

    PrimeSet(int from, int to) {

        size = to - from;

        set = new Prime * [size];

        index = 0;

    }

    ~PrimeSet() {

        delete[] set;

    }

    int count() {

        int count = 0;

        for (int i = 0; i < size; i++)

            if (set[i]->isPrime())

                count += 1;

        return count;

    }



    bool add(Prime* p) {

        if (index == size)  return false;

        set[index] = p;

        index += 1;

        return true;

    }

    bool isAllPrime() {

        std::cout << "PrimeSet's isAllPrime() call" << std::endl;

        for (int i = 0; i < index; i++)

            if (!set[i]->isPrime())

                return false;

        return true;

    }

private:

    Prime** set;

    int size, index;

};

class SuperPrime : public Prime {

public:

    SuperPrime() :Prime(0), pset(3) {  //为什么必须有？

    }

    SuperPrime(int n) :Prime(n), pset(3) {

        split();



    }

    ~SuperPrime() {

        delete Sum;

        delete Multi;

        delete SquareSum;

    }

    virtual bool isPrime() {   //类/对象的接口，更抽象说是外观

        std::cout << "SuperPrime's isPrime() call" << std::endl;

        if (Prime::isPrime() && pset.isAllPrime())

            return true;

        return false;

    }

private:

    PrimeSet pset;

    Prime* Sum;

    Prime* Multi;

    Prime* SquareSum;

    int size_N, N[10];



    void split() {   //工厂方法设计模式

        // number split into N

        int temp = number;

        int i;

        for (i = 0; temp > 0; i++) {

            int n = temp % 10;

            temp /= 10;

            N[i] = n;

        }

        size_N = i;

        Sum = new Prime(sum());

        Multi = new Prime(multi());

        SquareSum = new Prime(squareSum());

        pset.add(Sum);

        pset.add(Multi);

        pset.add(SquareSum);

    }

    int sum() {

        int sum_number = 0;

        for (int i = 0; i < size_N; i++) {

            sum_number += N[i];

        }

        return sum_number;

    }

    int multi() {

        int multi_num = 1;

        int i;

        for (i = 0; i < size_N; i++) {

            multi_num *= N[i];

        }

        return multi_num;

    }

    int squareSum() {

        int square = 0;

        int i;

        for (i = 0; i < size_N; i++)

            square += (N[i] * N[i]);

        return square;

    }

};

int main() {

    Prime p(13);

    SuperPrime sp(113);

    PrimeSet set(2);

    set.add(&sp);

    set.add(&p);

    std::cout << "How Many : " << set.count() << std::endl;

    return 0;

}