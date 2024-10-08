/**
 * filter_client.cpp
 *
 * Copyright (C) 2023-2024  Pablo Alvarado
 * EL5805 Procesamiento Digital de Señales
 * Escuela de Ingeniería Electrónica
 * Tecnológico de Costa Rica
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the authors nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "filter_client.h"

#include <cstring>
#include <iostream>

filter_client::filter_client(int *dir):dir(dir)
{
	filter_type = None;
	prueba.set_coefficients(std::array<sample_t, 6>{
      1, -1.9962282681026606, 1.0000000006886136,
      1,-1.9902746344470237,0.99111829673050256
    });
}

filter_client::~filter_client() {}

/**
 * The process callback for this JACK application is called in a
 * special realtime thread once for each audio cycle.
 *
 * This client does nothing more than copy data from its input
 * port to its output port. It will exit when stopped by 
   * the user (e.g. using Ctrl-C on a unix-ish operating system)
   */
bool filter_client::process(jack_nframes_t nframes, const sample_t *const in, sample_t *const out){

  	const sample_t *const end_ptr = in+nframes;
	const sample_t *ptr = in;
	sample_t *optr = out;
	
	/**
	 * Cascade Funcionality
	 */
	if (*dir == 'c'){
		switch (filter_type){
			case TWO:
				while(ptr != end_ptr){
					*optr++ = cascade_single.process<0>(*ptr++);
				}
				break;
			case THREE:
				while(ptr != end_ptr){
					*optr++ = cascade_band.process<0>(*ptr++);
				}
				break;
			case None:
				memcpy (out, in, sizeof(sample_t)*nframes);
				break;
			default:
				break;
		}
		
	/**
	 * Biquad Funcionality
	 */
	} else if (*dir == 'p'){
		while(ptr != end_ptr){
			*optr++ = prueba.process(*ptr++);
		}
	}
	return true;
}

bool filter_client::set(std::vector<std::array<sample_t, 6>> &coefficients){
	/**
	 * Search the order of the cascade
	 */
	if (coefficients.size() == 2){
		filter_type = TWO;
		cascade_single.set_biquads(coefficients);
		return true;
	}else if (coefficients.size() == 3){
		filter_type = THREE;
		cascade_band.set_biquads(coefficients);
		return true;
	}else{
		return false;
	}
}
