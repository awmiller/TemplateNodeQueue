#include "template_test.h"

TemplateTest::TemplateTest( int size ) {
  cout << "Creating TemplateTest" << endl;

  queue = NULL;
  test_values = NULL;
  test_size = size;
  test_index = -1;

  srand( time(NULL) );
}

TemplateTest::~TemplateTest() {
  if( queue != NULL ) {
    delete queue;
  }

  if( test_values != NULL ) {
    delete[] test_values;
  }

  cout << "Destroyed TemplateTest" << endl;
}

void TemplateTest::run_tests() {
  // Tests enqueue
  initialize_queue();
  // Tests isEmpty
  check_queue_is_not_empty();
  // Tests size
  check_queue_size();
  // Tests front
  check_queue_front();
  // Ensure size did not change
  check_queue_size();
  // Tests dequeue
  check_queue_dequeue();
  // Ensure size changed
  check_queue_size();
  // Ensure front is updated to next value
  check_queue_front();
  // Exercises isEmpty and dequeue
  clear_queue();
  // Ensure empty
  check_queue_is_empty();
  // Ensure default value returned
  check_queue_default_value();
}

void TemplateTest::initialize_queue() {
  queue = new Queue<Blarg>();
  test_values = new int[ test_size ];
  test_index = 0;

  for( int index = 0; index < test_size; index++ ) {
    int random_value = rand() % TemplateTest::TEST_RANGE;

    test_values[ index ] = random_value;
    queue->enqueue( Blarg(random_value) );
  }
}

void TemplateTest::check_queue_is_not_empty() {
  test_header( "queue is not empty" );
  print_test( ! queue->isEmpty() );
}

void TemplateTest::check_queue_is_empty() {
  test_header( "queue is empty" );
  print_test( queue->isEmpty() );
}

void TemplateTest::check_queue_size() {
  int expected_size = test_size - test_index;

  test_header( "queue size is " + to_string( expected_size ) );
  print_test( queue->size() == expected_size );
}

void TemplateTest::check_queue_front() {
  test_header( "queue front is " + to_string( expected_front() ) );
  print_test( queue->front().gb() == expected_front() );
}

void TemplateTest::check_queue_dequeue() {
  test_header( "dequeue should be " + to_string( expected_front() ) );
  print_test( queue->dequeue().gb() == expected_front() );

  test_index++;
}

void TemplateTest::clear_queue() {
  test_header( "clearing the queue (isEmpty and dequeue)" );

  while( ! queue->isEmpty() ) {
    queue->dequeue();
  }

  // Makes the assumption that program would fail if loop fails
  print_test( true );
}

void TemplateTest::check_queue_default_value() {
  test_header( "default value returned when dequeue called on empty Queue" );
  print_test( queue->dequeue().gb() == 0 );
}

void TemplateTest::test_header( string message ) {
  cout << "--- Testing " << message << " ---" << endl;
}

void TemplateTest::print_test( bool result ) {
  if( result ) {
    cout << "PASS";
  } else {
    cout << "FAIL";
  }

  cout << endl << endl;
}

int TemplateTest::expected_front() {
  return test_values[ test_index ];
}

