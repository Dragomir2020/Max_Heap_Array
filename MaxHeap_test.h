#ifndef MAXHEAP_TEST_H
#define MAXHEAP_TEST_H
/*
  MinHeap_test.h
  Unit tests for MinHeap
  
*/

#include "MaxHeap.h"
#include <stdexcept>
#include <string>
#include <queue>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include <cxxtest/TestSuite.h>

class PushSize : public CxxTest::TestSuite {
public:

  void testPushSize0() {
    MaxHeap<int> a;
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPushSize1() {
    MaxHeap<int> a;
    a.push(5);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testPushSize2() {
    MaxHeap<int> a;
    a.push(5);
    a.push(19);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
   void testPushSize3Ints() {
    MaxHeap<int> a;
    a.push(5);
    a.push(19);
    a.push(-10);
    TS_ASSERT_EQUALS(a.size(), 3);
  }
  
  void testPushSize3() {
    MaxHeap<string> a;
    a.push("blob");
    a.push("Billy");
    a.push("grape");
    TS_ASSERT_EQUALS(a.size(), 3);
  }
  
  void testPushSize4() {
    MaxHeap<string> a;
    a.push("brand");
    a.push("Hello World");
    a.push("Sentence B");
    a.push("This is so fun");
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testPushSize5() {
    MaxHeap<string> a;
    a.push("blue");
    a.push("Billy");
    a.push("grandma");
    a.push("Billy");
    a.push("billy");
    TS_ASSERT_EQUALS(a.size(), 5);
  }
  
  void testPushSize6() {
    MaxHeap<int> a;
    srand(time(0));
    for(int i=0;i<100;i++){
    	a.push(rand() % 50 + 1);
    }
    TS_ASSERT_EQUALS(a.size(), 100);
  }
  
  void testPushSize7() {
    MaxHeap<int> a;
    srand(time(0));
    for(int i=0;i<1000;i++){
    	a.push(rand() % 100 + 1);
    }
    TS_ASSERT_EQUALS(a.size(), 1000);
  }
  
};

class PushTop : public CxxTest::TestSuite {
public:

  void testPushTop0() {
    MaxHeap<int> a;
    TS_ASSERT_THROWS_ANYTHING(a.top());
  }
  
  void testPushTop1() {
    MaxHeap<int> a;
    a.push(5);
    TS_ASSERT_EQUALS(a.top(),5);
  }
  
  void testPushTop2() {
    MaxHeap<int> a;
    a.push(5);
    a.push(6);
    TS_ASSERT_EQUALS(a.top(),6);
  }
  
  void testPushTop3() {
    MaxHeap<int> a;
    a.push(5);
    a.push(6);
    a.push(7);
    TS_ASSERT_EQUALS(a.top(),7);
  }
  
  void testPushTop4() {
    MaxHeap<int> a;
    a.push(5);
    a.push(4);
    a.push(3);
    TS_ASSERT_EQUALS(a.top(),5);
  }
  
  void testPushTop5() {
    MaxHeap<int> a;
    a.push(5);
    a.push(4);
    a.push(8);
    a.push(6);
    TS_ASSERT_EQUALS(a.top(),8);
  }
  
  void testPushTop6() {
    srand(time(0));
    MaxHeap<int> a;
    int max = 0;
    for(int i = 0; i < 100; i++){
      int num = rand() % 1000;
      if(num > max){
        max = num;
      }
      a.push(num);
    }
    TS_ASSERT_EQUALS(a.top(),max);
  }
  
  void testPushTop7() {
    MaxHeap<int> a;
    a.push(-10);
    a.push(4);
    a.push(500);
    a.push(6021);
    a.push(-6021);
    TS_ASSERT_EQUALS(a.top(),6021);
  }
  void testPushTop8() {
    MaxHeap<int> a;
    a.push(-10);
    a.push(4);
    a.push(500);
    a.push(60);
    a.push(-6021);
    a.push(60);
    a.push(-6021);
    TS_ASSERT_EQUALS(a.top(),500);
  }
  void testPushTop9() {
    MaxHeap<int> a;
    a.push(-10);
    a.push(4);
    a.push(5);
    a.push(602);
    a.push(-50000);
    a.push(0);
    TS_ASSERT_EQUALS(a.top(),602);
  }
  void testPushTop10() {
    MaxHeap<int> a;
    a.push(-1000);
    a.push(0);
    a.push(-2000);
    a.push(0);
    a.push(-601);
    a.push(-6);
    TS_ASSERT_EQUALS(a.top(),0);
  }
  void testPushTop11() {
    MaxHeap<int> a;
    a.push(-10);
    TS_ASSERT_EQUALS(a.top(),-10);
  }
  
};


class CopyAssign : public CxxTest::TestSuite {
public:

  void testPushPop0() {
    MaxHeap<int> a;
    a.push(5);
    MaxHeap<int> b(a);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
  
  void testPushPop1() {
    MaxHeap<int> a;
    a.push(5);
    MaxHeap<int> b(a);
    a.push(10);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
  
  void testPushPop2() {
    MaxHeap<int> a;
    a.push(5);
    MaxHeap<int> b(a);
    b.push(10);
    TS_ASSERT_EQUALS(b.size(), 2);
    TS_ASSERT_EQUALS(b.top(), 10);
    TS_ASSERT_EQUALS(a.top(), 5);
  }
  
  void testPushPop3() {
    MaxHeap<int> a;
    a.push(5);
    MaxHeap<int> b;
    b.push(50);
    b.push(10);
    b = a;
    TS_ASSERT_EQUALS(b.size(), 1);
  }
  
  void testPushPop4() {
    MaxHeap<int> a;
    a.push(5);
    MaxHeap<int> b;
    b = a;
    a.push(10);
    TS_ASSERT_EQUALS(b.size(), 1);
  }
  
  void testPushPop5() {
    MaxHeap<int> a;
    a.push(5);
    a = a;
    TS_ASSERT_EQUALS(a.size(), 1);
    TS_ASSERT_EQUALS(a.top(), 5);
  }
  
  void testPushPop6() {
    MaxHeap<int> a;
    a.push(5);
    a.push(-5);
    a.push(0);
    MaxHeap<int> b(a);
    TS_ASSERT_EQUALS(a.size(), 3);
    TS_ASSERT_EQUALS(a.top(), 5);
  }
  
  void testPushPop7() {
    MaxHeap<int> a;
    a.push(5);
    MaxHeap<int> b;
    b = a;
    b.push(-20);
    TS_ASSERT_EQUALS(b.size(), 2);
    TS_ASSERT_EQUALS(b.top(), 5);
  }
  
  void testPushPop8() {
    MaxHeap<int> a;
    MaxHeap<int> b;
    b = a;
    TS_ASSERT_EQUALS(a.size(), 0);
    TS_ASSERT_THROWS_ANYTHING(a.top());
  }
  
  void testPushPop9() {
    MaxHeap<int> a;
    a.push(5);
    a.push(0);
    a.push(25);
    a.push(100);
    a.push(-100);
    a = a;
    TS_ASSERT_EQUALS(a.size(), 5);
    TS_ASSERT_EQUALS(a.top(), 100);
  }
  
  void testPushPop10() {
    MaxHeap<int> a;
    a.push(5);
    a.push(0);
    a.push(25);
    a.push(100);
    a.push(-100);
    MaxHeap<int> b;
    b = a;
    TS_ASSERT_EQUALS(a.size(), 5);
    TS_ASSERT_EQUALS(a.top(), 100);
  }
  
};


class PushPop : public CxxTest::TestSuite {
public:

  void testPushPop0() {
    MaxHeap<int> a;
    a.push(5);
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPushPop1() {
    MaxHeap<int> a;
    a.push(5);
    a.push(6);
    a.push(7);
    a.pop();
    TS_ASSERT_EQUALS(a.top(), 6);
  }
  
  void testPushPop2() {
    MaxHeap<int> a;
    a.push(5);
    a.push(6);
    a.push(7);
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS(a.top(), 5);
  }
  
  void testPushPop3() {
    MaxHeap<int> a;
    a.push(5);
    a.push(6);
    a.push(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 1);
    a.pop();
    a.push(99);
    TS_ASSERT_EQUALS(a.top(), 99);
    TS_ASSERT_EQUALS(a.size(), 1);
  }
  
  void testPushPop4() {
    MaxHeap<int> a;
    a.push(5);
    a.push(6);
    a.push(7);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.pop();
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 1);
    a.pop();
    a.pop();
    a.pop();
    a.push(99);
    TS_ASSERT_EQUALS(a.top(), 99);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.push(5);
    TS_ASSERT_EQUALS(a.top(), 99);
    TS_ASSERT_EQUALS(a.size(), 2);
  }
  
  void testPushPop5() {
    MaxHeap<int> a;
    a.push(5);
    a.pop();
    a.pop();
    a.pop();
    a.pop();
    TS_ASSERT_THROWS_ANYTHING(a.top());
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPushPop6() {
    MaxHeap<int> a;
    a.push(5);
    a.push(15);
    a.push(6);
    a.push(16);
    a.push(-5);
    a.push(-15);
    TS_ASSERT_EQUALS(a.top(), 16);
    TS_ASSERT_EQUALS(a.size(), 6);
    a.pop();
    TS_ASSERT_EQUALS(a.top(), 15);
    TS_ASSERT_EQUALS(a.size(), 5);
    a.pop();
    TS_ASSERT_EQUALS(a.top(), 6);
    TS_ASSERT_EQUALS(a.size(), 4);
    a.pop();
    TS_ASSERT_EQUALS(a.top(), 5);
    TS_ASSERT_EQUALS(a.size(), 3);
    a.pop();
    TS_ASSERT_EQUALS(a.top(), -5);
    TS_ASSERT_EQUALS(a.size(), 2);
    a.pop();
    TS_ASSERT_EQUALS(a.top(), -15);
    TS_ASSERT_EQUALS(a.size(), 1);
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPushPop7() {
    MaxHeap<int> a;
    priority_queue<int> b;
    for(int i = 0; i < 1000; i++){
      int r = rand();
      a.push(r);
      b.push(r);
      TS_ASSERT_EQUALS(a.top(), b.top());
    }
    
    for(int i = 0; i < 1000; i++){
      TS_ASSERT_EQUALS(a.top(), b.top());
      a.pop();
      b.pop();
    }
  }
  
  void testPushPop8() {
    MaxHeap<int> a;
    a.push(5);
    a.push(5);
    a.push(5);
    a.push(5);
    a.pop();
    a.push(5);
    TS_ASSERT_EQUALS(a.size(), 4);
  }
  
  void testPushPop9() {
    MaxHeap<string> a;
    a.pop();
    a.push("Hello World!");
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
  void testPushPop10() {
    MaxHeap<string> a;
    a.pop();
    a.push("Hello World!");
    a.push("Yes");
    TS_ASSERT_EQUALS(a.size(), 2);
    TS_ASSERT_EQUALS(a.top(), "Yes");
  }
  
  void testPushPop11() {
    MaxHeap<string> a;
    a.pop();
    a.push("Hello World!");
    a.pop();
    TS_ASSERT_EQUALS(a.isEmpty(), 1);
  }
  
  void testPushPop12() {
    MaxHeap<int> a;
    a.push(5);
    a.pop();
    a.push(0);
    a.pop();
    a.push(50);
    a.pop();
    a.push(-100);
    a.pop();
    TS_ASSERT_EQUALS(a.size(), 0);
  }
  
};

#endif
