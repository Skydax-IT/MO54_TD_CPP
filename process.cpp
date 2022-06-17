#include "process.h"

void process::execute() {
    _loader->load(_storage);
    _calc->compute(_storage);
    _writer->write(_storage);
}
