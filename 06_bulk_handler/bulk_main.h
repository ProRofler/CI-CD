#pragma once

#include <memory>

#include "bulk_builder.h"  // TRY PIMPL later
// class bulk_builder;

class bulk_main {
   private:
    std::unique_ptr<bulk_builder> p_builer;

   public:
    void start();
};