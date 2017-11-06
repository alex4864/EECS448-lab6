#include "LinkedListTester.h"

void LinkedListTester::runTests()
{
  std::cout << "Test 1: ";
  std::cout << "\n(a) For new list isEmpty() == true: ";
  printTestStatus(test1a());
  std::cout << "\n(b) Adding item to list causes isEmpty() == false: ";
  printTestStatus(test1b());
  std::cout << "\n(c) Removing all items causes isEmpty() == true: ";
  printTestStatus(test1c());

  std::cout << "\n\nTest 2: ";
  std::cout << "\n(a) Empty lists have size 0: ";
  printTestStatus(test2a());
  std::cout << "\n(b) List with one add has size 1: ";
  printTestStatus(test2b());
  std::cout << "\n(c) List with two adds has size 2: ";
  printTestStatus(test2c());
  std::cout << "\n(d) List with two adds and two removes has size 0: ";
  printTestStatus(test2d());

  std::cout << "\n\nTest 3: ";
  std::cout << "\n(a) Searches find items in list: ";
  printTestStatus(test3a());
  std::cout << "\n(b) Searches do not find items not in list: ";
  printTestStatus(test3b());

  std::cout << "\n\nTest 4: ";
  std::cout << "\n(a) AddBack() properly inserts element at back of list: ";
  printTestStatus(test4a());
  std::cout << "\n(b) AddBack() properly inserts the correct number of elements: ";
  printTestStatus(test4b());

  std::cout << "\n\nTest 5: ";
  std::cout << "\n(a) AddFront() properly inserts element at front of list: ";
  printTestStatus(test5a());
  std::cout << "\n(b) AddFront() properly inserts the correct number of elements: ";
  printTestStatus(test5b());

  std::cout << "\n\nTest 6: ";
  std::cout << "\n(a) RemoveBack() properly removes correct number of elements from list: ";
  printTestStatus(test6a());
  std::cout << "\n(b) RemoveBack() removes correct elements from list: ";
  printTestStatus(test6b());

  std::cout << "\n\nTest 7: ";
  std::cout << "\n(a) RemoveFront() properly removes correct number of elements from list: ";
  printTestStatus(test7a());
  std::cout << "\n(b) RemoveFront() removes correct number of elements from list: ";
  printTestStatus(test7b());
}

void LinkedListTester::printTestStatus(bool testStatus)
{
  if(testStatus)
  {
    std::cout << "passed";
  }
  else
  {
    std::cout << "FAILED";
  }
}

// for new list isEmpty()==true
bool LinkedListTester::test1a()
{
  LinkedListOfInts list;
  if(!list.isEmpty())
  {
    return false;
  }
  else
  {
    return true;
  }
}

// non empty list isEmpty()==false
bool LinkedListTester::test1b()
{
  LinkedListOfInts list;
  list.addFront(1);
  if(list.isEmpty())
  {
    return false;
  }
  else
  {
    return true;
  }
}

// empty
bool LinkedListTester::test1c()
{
  LinkedListOfInts list;
  list.addFront(1);
  list.removeFront();
  if(!list.isEmpty())
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test2a()
{
  LinkedListOfInts list;
  if(list.size() != 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test2b()
{
  LinkedListOfInts list;
  list.addFront(1);
  if(list.size() != 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test2c()
{
  LinkedListOfInts list;
  list.addFront(1);
  list.addBack(2);
  if(list.size() != 2)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test2d()
{
  LinkedListOfInts list;
  list.addFront(1);
  list.addBack(2);
  list.removeFront();
  list.removeBack();

  if(list.size() != 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test3a()
{
  LinkedListOfInts list;
  list.addBack(1);
  list.addFront(2);
  list.addBack(3);

  if(!list.search(1))
  {
    return false;
  }
  if(!list.search(2))
  {
    return false;
  }
  if(!list.search(3))
  {
    return false;
  }
  return true;
}

bool LinkedListTester::test3b()
{
  LinkedListOfInts list;
  list.addBack(1);
  list.addFront(2);
  list.addBack(3);

  if(list.search(4))
  {
    return false;
  }
  if(list.search(5))
  {
    return false;
  }
  if(list.search(-2))
  {
    return false;
  }
  return true;
}

bool LinkedListTester::test4a()
{
  LinkedListOfInts list;
  list.addFront(1);
  list.addFront(2);
  list.addBack(3);
  if(list.toVector()[2] != 3)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test4b()
{
  LinkedListOfInts list;
  list.addBack(1);
  list.addBack(2);
  list.addBack(3);
  if(list.toVector().size() != 3)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test5a()
{
  LinkedListOfInts list;
  list.addBack(1);
  list.addBack(2);
  list.addFront(3);
  if(list.toVector()[0] != 3)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test5b()
{
  LinkedListOfInts list;
  list.addFront(1);
  list.addFront(2);
  list.addFront(3);
  if(list.toVector().size() != 3)
  {
    return false;
  }
  else
  {
    return true;
  }
}


bool LinkedListTester::test6a()
{
  LinkedListOfInts list;
  list.addBack(1);
  list.addBack(2);
  list.removeBack();
  list.removeBack();
  if(list.toVector().size() != 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test6b()
{
  LinkedListOfInts list;
  list.addBack(1);
  list.addBack(2);
  list.removeBack();
  if(list.toVector().back() != 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test7a()
{
  LinkedListOfInts list;
  list.addFront(1);
  list.addFront(2);
  list.removeFront();
  list.removeFront();
  if(list.toVector().size() != 0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

bool LinkedListTester::test7b()
{
  LinkedListOfInts list;
  list.addFront(1);
  list.addFront(2);
  list.removeFront();
  if(list.toVector().front() != 1)
  {
    return false;
  }
  else
  {
    return true;
  }
}
