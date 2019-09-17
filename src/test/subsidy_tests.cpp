// Copyright (c) 2014-2018 The Dash Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "validation.h"

#include "test/test_dash.h"

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(subsidy_tests, TestingSetup)

BOOST_AUTO_TEST_CASE(block_subsidy_test)
{
    const Consensus::Params& consensusParams = Params(CBaseChainParams::MAIN).GetConsensus();

    uint32_t nPrevBits;
    int32_t nPrevHeight;
    CAmount nSubsidy;

    nPrevBits = 0x1c4a47c4;
    nPrevHeight = 4249;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 5000000000ULL);

    // 1st subsidy reduction happens here

    // details for block 210240 (subsidy returned will be for block 210241)
    nPrevBits = 0x1b10d50b;
    nPrevHeight = 210240;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 4550000000ULL);
}

BOOST_AUTO_TEST_SUITE_END()
