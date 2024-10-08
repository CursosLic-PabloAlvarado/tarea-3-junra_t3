/**
 * passthrough_client.h
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

#ifndef _PASSTHROUGH_CLIENT_H
#define _PASSTHROUGH_CLIENT_H


#include "jack_client.h"
#include "cascade.h"

/**
 * Jack client class
 *
 * This class wraps some basic jack functionality.
 */
class filter_client : public jack::client {
    
  public:
    enum FilterType {TWO, THREE, None};
    typedef jack::client::sample_t sample_t;
    
    /**
     * The default constructor performs some basic connections.
     */
    filter_client(int* dir);
    ~filter_client();

    /**
		 * Functionality
		 * @param nframes amount of frames of audio per cycle
		 * @param in pointer to the input buffer
		 * @param out pointer to the saudio output buffer
		 */
    virtual bool process(jack_nframes_t nframes,
                        const sample_t *const in,
                        sample_t *const out) override;


    /**
     * Sets coefficients to both cascade members
     * @param coefficients matrix of coefficeints that are passed to cascade
     * */                    
    bool set(std::vector<std::array<sample_t, 6>> &coefficients);
    
  private:
    int *dir;
    FilterType filter_type;
    cascade<2> cascade_single;
    cascade<3> cascade_band;
    biquad prueba;

};



#endif
