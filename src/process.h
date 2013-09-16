#ifndef PROCESS_H_
#define PROCESS_H_

#include <memory>
#include <vector>

#include "object.h"
#include "thread.h"


namespace bunnylang {

class Process : public Object {
	// field
private:
	std::vector<std::shared_ptr<Thread> > threads_;

	// method
public:
	Process();
	~Process();

	// getter/setter
public:
};

} /* namespace bunnylang */
#endif /* PROCESS_H_ */
