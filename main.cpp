#include <string>
#include <iostream>

#include <observe/event.h>

int main() {
  // events can be valueless
  observe::Event<> eventA;

  // or have arguments
  observe::Event<std::string, float> eventB;

  observe::Event<int> eventC;

    // connect will always trigger when an event is triggered
  eventA.connect([](){
    std::cout << "A triggered" << std::endl;
  });
  
  // observers will remove themselves from the event on destroy or reset
  observe::Observer observer = eventB.createObserver([](const std::string &str, float v){ 
    std::cout << "B triggered with " << str << " and " << v << std::endl;
  });

  // call emit to trigger all observers
  eventA.emit();
  eventB.emit("meaning of life", 42);

  // `observe::Observer` can store any type of observer
  // previous observers will be removed
  observer.observe(eventC, [](int count){ std::cout << "I witness C with " << count << std::endl; });
  eventC.emit(123);
  eventC.emit(234);
  eventC.emit(1);
  eventC.emit(2);
  eventC.emit(42);

    // to remove an observer without destroying the object, call reset
  observer.reset();
}
