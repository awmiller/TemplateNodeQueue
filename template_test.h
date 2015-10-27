#ifndef __TEMPLATE_TEST_H__
#define __TEMPLATE_TEST_H__

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "queue.h"

using namespace std;

class Blarg {
  public:
    Blarg() : bleerg( 0 ) {}
    Blarg( int b ) : bleerg(b) {}
    int gb() { return bleerg; }
  private:
    int bleerg;
};

class TemplateTest {
  public:
    TemplateTest( int );
    ~TemplateTest();
    void run_tests();

    static const int TEST_RANGE = 10000;

  private:
    void initialize_queue();

    void test_header( string );
    void print_test( bool );

    void check_queue_is_not_empty();
    void check_queue_is_empty();
    void check_queue_size();
    void check_queue_front();
    void check_queue_dequeue();
    void clear_queue();
    void check_queue_default_value();

    int expected_front();

    Queue<Blarg> * queue;
    int test_size;
    int * test_values;
    int test_index;
};

#endif