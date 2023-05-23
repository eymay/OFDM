# -*- coding: utf-8 -*-

#
# SPDX-License-Identifier: GPL-3.0
#
# GNU Radio Python Flow Graph
# Title: Maximum Ratio Combiner
# GNU Radio version: 3.10.1.1

from gnuradio import blocks
from gnuradio import gr
from gnuradio.filter import firdes
from gnuradio.fft import window
import sys
import signal







class mrc_hier(gr.hier_block2):
    def __init__(self):
        gr.hier_block2.__init__(
            self, "Maximum Ratio Combiner",
                gr.io_signature.makev(4, 4, [gr.sizeof_gr_complex*64, gr.sizeof_gr_complex*64, gr.sizeof_gr_complex*64, gr.sizeof_gr_complex*64]),
                gr.io_signature(1, 1, gr.sizeof_gr_complex*64),
        )

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 32000

        ##################################################
        # Blocks
        ##################################################
        self.blocks_vector_to_stream_0_0 = blocks.vector_to_stream(gr.sizeof_gr_complex*1, 64)
        self.blocks_vector_to_stream_0 = blocks.vector_to_stream(gr.sizeof_gr_complex*1, 64)
        self.blocks_stream_to_vector_0_0 = blocks.stream_to_vector(gr.sizeof_gr_complex*1, 64)
        self.blocks_stream_to_vector_0 = blocks.stream_to_vector(gr.sizeof_gr_complex*1, 64)
        self.blocks_multiply_xx_0_0 = blocks.multiply_vcc(64)
        self.blocks_multiply_xx_0 = blocks.multiply_vcc(64)
        self.blocks_float_to_complex_0_0 = blocks.float_to_complex(64)
        self.blocks_float_to_complex_0 = blocks.float_to_complex(64)
        self.blocks_divide_xx_0 = blocks.divide_cc(64)
        self.blocks_conjugate_cc_0_1 = blocks.conjugate_cc()
        self.blocks_conjugate_cc_0 = blocks.conjugate_cc()
        self.blocks_complex_to_mag_squared_0_0 = blocks.complex_to_mag_squared(64)
        self.blocks_complex_to_mag_squared_0 = blocks.complex_to_mag_squared(64)
        self.blocks_add_xx_0_0_0 = blocks.add_vcc(64)
        self.blocks_add_xx_0_0 = blocks.add_vcc(64)


        ##################################################
        # Connections
        ##################################################
        self.connect((self.blocks_add_xx_0_0, 0), (self.blocks_divide_xx_0, 0))
        self.connect((self.blocks_add_xx_0_0_0, 0), (self.blocks_divide_xx_0, 1))
        self.connect((self.blocks_complex_to_mag_squared_0, 0), (self.blocks_float_to_complex_0, 0))
        self.connect((self.blocks_complex_to_mag_squared_0, 0), (self.blocks_float_to_complex_0, 1))
        self.connect((self.blocks_complex_to_mag_squared_0_0, 0), (self.blocks_float_to_complex_0_0, 1))
        self.connect((self.blocks_complex_to_mag_squared_0_0, 0), (self.blocks_float_to_complex_0_0, 0))
        self.connect((self.blocks_conjugate_cc_0, 0), (self.blocks_stream_to_vector_0, 0))
        self.connect((self.blocks_conjugate_cc_0_1, 0), (self.blocks_stream_to_vector_0_0, 0))
        self.connect((self.blocks_divide_xx_0, 0), (self, 0))
        self.connect((self.blocks_float_to_complex_0, 0), (self.blocks_add_xx_0_0_0, 0))
        self.connect((self.blocks_float_to_complex_0_0, 0), (self.blocks_add_xx_0_0_0, 1))
        self.connect((self.blocks_multiply_xx_0, 0), (self.blocks_add_xx_0_0, 0))
        self.connect((self.blocks_multiply_xx_0_0, 0), (self.blocks_add_xx_0_0, 1))
        self.connect((self.blocks_stream_to_vector_0, 0), (self.blocks_multiply_xx_0, 1))
        self.connect((self.blocks_stream_to_vector_0_0, 0), (self.blocks_multiply_xx_0_0, 1))
        self.connect((self.blocks_vector_to_stream_0, 0), (self.blocks_conjugate_cc_0, 0))
        self.connect((self.blocks_vector_to_stream_0_0, 0), (self.blocks_conjugate_cc_0_1, 0))
        self.connect((self, 0), (self.blocks_multiply_xx_0, 0))
        self.connect((self, 1), (self.blocks_multiply_xx_0_0, 0))
        self.connect((self, 2), (self.blocks_complex_to_mag_squared_0, 0))
        self.connect((self, 2), (self.blocks_vector_to_stream_0, 0))
        self.connect((self, 3), (self.blocks_complex_to_mag_squared_0_0, 0))
        self.connect((self, 3), (self.blocks_vector_to_stream_0_0, 0))


    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate

