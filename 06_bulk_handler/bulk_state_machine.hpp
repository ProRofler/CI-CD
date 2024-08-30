#pragma once

class bulk_state_machine {
   private:
    bool dynamic = false;

   public:
    bool is_dynamic_state() { return dynamic; }
    void switch_state();
};