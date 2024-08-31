#pragma once

#include <memory>

#include "bulk_builder.h" // TRY PIMPL later
// class bulk_builder;

class bulk_main {
   private:
    bool run = true;

    std::unique_ptr<bulk_builder> p_builer;

   public:
    void start();
    void exit();
};