// Copyright Steinwurf ApS 2011-2013.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#pragma once

#include "internal/factory_interface.hpp"
#include "internal/decoder_factory_wrapper.hpp"
//#include "decoder.hpp"

namespace kodo
{
    class decoder_factory : public factory_interface
    {
    public:
        decoder_factory(kodo::algorithm algorithm,
                        kodo::fieldtype field_type,
                        uint32_t max_symbols,
                        uint32_t max_symbol_size,
                        bool trace_enabled);

        decoder build();

        void set_symbols(uint32_t symbols);

        void set_symbol_size(uint32_t symbol_size);

        uint32_t max_symbols() const;

        uint32_t max_symbol_size() const;

        uint32_t max_block_size() const;

        uint32_t max_payload_size() const;

    private:
        factory_interface* m_factory_wrapper;
    };

}
