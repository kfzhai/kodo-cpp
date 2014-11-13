// Copyright Steinwurf ApS 2014.
// Distributed under the "STEINWURF RESEARCH LICENSE 1.0".
// See accompanying file LICENSE.rst or
// http://www.steinwurf.com/licensing

#include <cstdint>

#include <gtest/gtest.h>

#include <kodocpp/kodocpp.hpp>

void test_symbol_encoder(uint32_t symbols, uint32_t symbol_size,
                        kodocpp::code_type code_type,
                        kodocpp::finite_field finite_field,
                        bool trace_enabled)
{
    kodocpp::encoder_factory encoder_factory(
        code_type,
        finite_field,
        symbols,
        symbol_size,
        trace_enabled);

    kodocpp::encoder encoder = encoder_factory.build();
    EXPECT_EQ(symbols, encoder.symbols());
}

void test_symbol_decoder(uint32_t symbols, uint32_t symbol_size,
                        kodocpp::code_type code_type,
                        kodocpp::finite_field finite_field,
                        bool trace_enabled)
{
    kodocpp::decoder_factory decoder_factory(
        code_type,
        finite_field,
        symbols,
        symbol_size,
        trace_enabled);

    kodocpp::decoder decoder = decoder_factory.build();
    EXPECT_EQ(symbols, decoder.symbols());
}


TEST(TestSymbols, invoke_api)
{
    //This is what is expectede for coder.symbol_size()
    uint32_t max_symbols = 32;
    uint32_t max_symbol_size = 160;

    // Testing ecoders
    test_symbol_encoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::full_rlnc,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_encoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::full_rlnc,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_encoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::on_the_fly,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_encoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::on_the_fly,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_encoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::sliding_window,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_encoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::sliding_window,
                       kodocpp::finite_field::binary8,
                       false);

    // Testing decoders
    test_symbol_decoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::full_rlnc,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_decoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::full_rlnc,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_decoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::on_the_fly,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_decoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::on_the_fly,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_decoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::sliding_window,
                       kodocpp::finite_field::binary8,
                       false);

    test_symbol_decoder(max_symbols, max_symbol_size,
                       kodocpp::code_type::sliding_window,
                       kodocpp::finite_field::binary8,
                       false);
}
