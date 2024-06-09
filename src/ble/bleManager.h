#include "Arduino.h"
#include <stdint.h>

class BleManager {
  public:
    void init();
    void scan();
    void setConnectionListener(void (&onConnected)(), void (&onDisconnected)());
    void setTextUpdatedListener(void (&onTextUpdated)(String));
    void setAttributesUpdatedListener(void (&onAttributesUpdated)(Attributes));
};