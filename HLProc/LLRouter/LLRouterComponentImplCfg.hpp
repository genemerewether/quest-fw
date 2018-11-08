/*
 * LLRouterComponentImplCfg.hpp
 *
 *  Created on: Feb 22, 2017
 *      Author: tcanham
 */

#ifndef LLROUTER_LLROUTERCOMPONENTIMPLCFG_HPP_
#define LLROUTER_LLROUTERCOMPONENTIMPLCFG_HPP_

enum {
    SERIAL_BUFFER_SIZE = 400, // 400 bytes, twice what we can send
    SERIAL_RECEIVE_BUFFER_POOL_SIZE = 10 // allows slip of 10 cycles
};

#endif /* LLROUTER_LLROUTERCOMPONENTIMPLCFG_HPP_ */