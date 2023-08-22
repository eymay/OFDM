<p><strong>Design and Applications of Basic Communication
Systems</strong></p>
<p><strong>EHB 481E</strong></p>
<p><span class="smallcaps">MIMO OFDM with GNU Radio</span></p>
<p>Nurullah Aksu</p>
<p>M. Eymen Ünay</p>
</div>
<h1 id="purpose-of-project">Purpose of Project</h1>
<p>In this project Orthogonal Frequency Division Multiplexing (OFDM)
system on GNU Radio is implemented and the path towards MIMO-OFDM system
is investigated. The purpose is to better understand transmitter and
receiver structure of OFDM and to discuss designing MIMO systems.</p>
<h1 id="theoretical-background-information">Theoretical Background
Information</h1>
<h2 id="ofdm">OFDM</h2>
<p>OFDM is a digital modulation technique widely used in next generation
communication systems. OFDM allows simultaneous transmission of data
symbols on each subcarrier by dividing the available frequency spectrum
into multiple orthogonal subcarriers <span class="citation"
data-cites="gold_smith wireless_book"></span>. OFDM provides several
advantages such as high spectral efficiency, robustness against
frequency-selective fading and resistance to multipath interference.</p>
<p>OFDM transmits high-rate signals by splitting the serial high-rate
signal into parallel low-bit streams. Following the conversion of the
serial data symbols to parallel data symbols, the time-domain OFDM
symbol is produced by the inverse fast Fourier transform (IFFT) block as
<span class="citation" data-cites="arslan2021wireless"></span>,</p>
<p><span class="math display">$$x_m(t)=
\dfrac{1}{\sqrt{N}}\sum\limits_{k=0}^{N-1} X_m(k) e^{j2\pi k\triangle
ft} \hspace{1cm} {0\le t\le T_s}.$$</span></p>
<p>Where N is the number of subcarriers, <span
class="math inline"><em>X</em><sub><em>m</em></sub>(<em>k</em>)</span>
is the transmitted data symbol at the <span
class="math inline"><em>k</em><sup><em>t</em><em>h</em></sup></span>
subcarrier of the <span
class="math inline"><em>m</em><sup><em>t</em><em>h</em></sup></span>
OFDM symbol, <span class="math inline">△<em>f</em></span> is the
subcarrier spacing and <span
class="math inline"><em>T</em><sub><em>s</em></sub></span> is the
duration of the OFDM symbol. With a sampling rate of <span
class="math inline"><em>T</em><sub><em>s</em></sub>/<em>N</em></span>,
the discrete form of the time-domain OFDM symbol can be expressed as,
<span class="math display">$$x_m(n)=
\dfrac{1}{\sqrt{N}}\sum\limits_{k=0}^{N-1} X_m(k) e^{j2\pi k\triangle
f(T_s/N)} \hspace{0.5cm} {0\le n\le N-1}.$$</span></p>
<p>By assuring <span
class="math inline"><em>T</em><sub><em>s</em></sub></span> = <span
class="math inline">$\dfrac{1}{\triangle f}$</span> , the subcarriers’
orthogonality is attained. As a result, the following is how the OFDM
symbol in time domain is written as, <span
class="math display">$$x_m(n)=
\dfrac{1}{\sqrt{N}}\sum\limits_{k=0}^{N-1} X_m(k) e^{j2\pi kn/N}
\hspace{0.5cm} {0\le n\le N-1}.$$</span></p>
<p>Then, the signal is transmitted over the channel after parallel to
series conversion and adding cyclic prefix to avoid interference. The
received signal is converted frequency domain signal by utilizing
forward FFT after the channel estimation process. Finally, demodulation
steps are performed and the actual message is obtained. The general
block diagram is shown in Figure <a href="#fig:block_diagram"
data-reference-type="ref" data-reference="fig:block_diagram">1</a></p>
<figure id="fig:block_diagram">
<img src="./Figures/Figures/ofdm_block_diagram.jpg" title="fig:"
style="width:70.0%" />
<figcaption>General block diagram of OFDM <span class="citation"
data-cites="block_diagram"></span></figcaption>
</figure>
<h2 id="mimo">MIMO</h2>
<p>As one of the diversity techniques MIMO, is a wireless communication
technology that improves the performance of wireless communication
systems by transmitting the signal over multiple transmitter antenna and
receiving it from multiple receiver antennas <span class="citation"
data-cites="wireless_book general_mimo"></span>. One of the main
purposes of the MIMO systems is to increase the channel capacity and
this is succeeded by establishing multiple channels by using multiple
antennas <span class="citation" data-cites="general_mimo"></span>. The
key idea behind MIMO is to create multiple parallel communication
channels, each operating on the same frequency yet with different
antenna configurations.</p>
<p>Spatial multiplexing where multiple data streams are transmitted
simultaneously using different antennas, is enabled with MIMO. Thereby,
increased data throughput can be obtained, as the system can transmit
and receive multiple independent data streams concurrently. MIMO also
helps to combat fading and interference, as the signals from multiple
antennas can be combined or separated to mitigate the effects of
multipath propagation. Hence, lower error rates can be achieved with
MIMO systems in wireless communications <span class="citation"
data-cites="wireless_book"></span>.</p>
<p>In conclusion, higher data rates, increased system capacity, improved
reliability and enhanced coverage can be accomplished with MIMO
systems.</p>
<h3 id="sec:mrc">Maximum Ratio Combining</h3>
<p>When there are multiple antennas at the receiver side, the received
signals should be combined to reach the actual message. One of the
combining techniques is Maximum Ratio Combining (MRC). In this method,
the received signals coming from multiple antennas are combined to
improve the overall signal quality and mitigate the effects of fading
and interference <span class="citation"
data-cites="gold_smith alamouti"></span>. Another advantage of the MRC
is that different antennas may experience independent fading and
interference conditions. By combining these independent signals, MRC
provides diversity gain, which improves the system’s reliability and
performance.</p>
<p>In MRC, the received signals from the N receiver antennas are
weighted and combined. This technique can be expressed theoretically.
The received signal from the N receiver antenna can be expressed as,</p>
<p><span
class="math display"><em>y</em><sub><em>N</em></sub> = <em>h</em><sub><em>N</em></sub><em>s</em> + <em>n</em><sub><em>N</em></sub>.</span></p>
<p>where <span
class="math inline"><em>h</em><sub><em>N</em></sub></span> is the
channels of the N receiver antenna, <span
class="math inline"><em>s</em></span> is the message signal and the
<span class="math inline"><em>n</em><sub><em>N</em></sub></span> is the
AWGN noise. These received signals are combined with MRC method. In
detail, these signals are weighted according to their channel
characteristics and then they are combined. This procedure can be
expressed as,</p>
<p><span class="math display">$$\Tilde{s}=\frac{h_0^* y_0+h_1^*
y_1+\ldots+h_{N-1}^*
y_{N-1}}{\left|h_0\right|^2+\left|h_1\right|^2+\ldots+\left|h_{N-1}\right|^2}$$</span></p>
<p>where <span class="math inline">$\Tilde{s}$</span> is the combined
signal. After that, detection and demodulation processes are
performed.</p>
<h1 id="practical-background-information">Practical Background
Information</h1>
<h2 id="sdr">SDR</h2>
<p>Software Defined Radio (SDR) is used to prototype wireless
communication systems and observe real life performance of these
systems. SDR acts like a bridge with its RF interface between wireless
signals and the host computer. The host computer can process the
incoming RF signals by performing various signal processing operations.
The communication system gets implemented in software with SDR’s instead
of hardware.</p>
<p>In this project Ettus USRP B200 mini SDR was used. It has a wide
frequency range of 70MHz - 6GHz, a programmable FPGA, high-speed USB 3
and open source driver support <span class="citation"
data-cites="Brand2023May"></span>. The internal block diagram of the SDR
used is presented in Figure <a href="#fig:ettus"
data-reference-type="ref" data-reference="fig:ettus">2</a>.</p>
<figure id="fig:ettus">
<img src="./Figures/b200usrp.png" title="fig:" style="width:90.0%" />
<figcaption>Block diagram of Ettus USRP B200 mini</figcaption>
</figure>
<h2 id="gnu-radio">GNU Radio</h2>
<p>GNU Radio is a free and open source software designed to provide
signal processing blocks which can be combined and used by the user with
an SDR or in a simulation. The signal processing blocks are engineered
to run as fast as possible but their interfaces can be as simple as a
flowgraph. GNU Radio can be used as a real time system, meaning all the
processing can be complete under the sampling period of the system
allowing it to be used in a large number of fields.</p>
<p>The source code of GNU Radio is publicly available. Performance
critical, commonly used blocks are mainly written in C++ and the rest is
in Python. GNU Radio can be used as a library in a Python script or its
companion application can be used. The GNU Radio Companion provides an
interface similar to Simulink. Under the hood, the application creates a
Python script corresponding to the input flowgraph. It is possible to
further modify the Python script or directly embed custom Python blocks
into the flowgraph.</p>
<h1 id="project-steps">Project Steps</h1>
<h2 id="ofdm-transmitter">OFDM Transmitter</h2>
<p>In this section, OFDM transmitter structure in GNU Radio will be
described.</p>
<figure id="fig:crcqpsk">
<img src="./Figures/Figures/CRC_and_qpsk_Tx.png" title="fig:"
style="width:100.0%" />
<figcaption>CRC and modulation system in OFDM transmitter.</figcaption>
</figure>
<p>The generation and modulation of the data can be seen in Figure <a
href="#fig:crcqpsk" data-reference-type="ref"
data-reference="fig:crcqpsk">3</a>. Message data is generated repeatedly
in <em>Random Source</em> block. The size of the data is adjustable.
This data is packaged and tagged after <em>Stream to Tagged Stream</em>
block. Packet length is determined by tagging process. Then error
detection codes are added by <em>Stream CRC32</em> block. Finally, the
payload bits and header bits which are used in channel estimation
process are generated.</p>
<p>The header bits and the payload bits are modulated separately in the
<em>Chunks to Symbol</em> block. After this step, data is ready for the
OFDM processes.</p>
<p>File sources can be used instead of random data sources to analyze
errors more easily. Any binary can be sent however text file is used due
to its simplicity. The configuration for a <em>File Source</em> block
can be seen in Figure <a href="#fig:filesource"
data-reference-type="ref"
data-reference="fig:filesource">[fig:filesource]</a>. The full path of
the file should be given and the output type should be selected
according to the system using the data. The text used in this project is
shown in Figure <a href="#fig:filesource_data" data-reference-type="ref"
data-reference="fig:filesource_data">4</a>.</p>
<figure id="fig:filesource_data">
<img src="./Figures/Figures/file_source.png" title="fig:"
style="width:80.0%" />
<img src="./Figures/Figures/transmitted_data_txt.png" title="fig:"
style="width:90.0%" />
<figcaption>Data to be transmitted.</figcaption>
</figure>
<p>The <em>Tagged Stream Mux</em> block combines the QPSK modulated data
and BPSK modulated header into one stream. With the help of <em>QT GUI
Constellation Sink</em> block, the constellation is shown in Figure <a
href="#fig:constell_tx" data-reference-type="ref"
data-reference="fig:constell_tx">5</a>.</p>
<figure id="fig:constell_tx">
<img src="./Figures/Figures/Modulated data.png" title="fig:"
style="width:70.0%" />
<figcaption>Constellation of the modulated data.</figcaption>
</figure>
<figure id="fig:ofdm_tx">
<img src="./Figures/Figures/Tx_ofdm_usrp.png" title="fig:"
style="width:90.0%" />
<figcaption>OFDM transmitter system.</figcaption>
</figure>
<p>In Figure <a href="#fig:ofdm_tx" data-reference-type="ref"
data-reference="fig:ofdm_tx">6</a>, the OFDM transmitter system is
shown. <em>Virtual Source</em> with the <em>Pre-OFDM</em> id contains
the combined header and data payload. The whole signal passes through 3
main blocks before transmission. Firstly, <em>OFDM Carrier
Allocator</em> performs Series to Parallel transformation together with
pilot carrier insertion. The input stream is split into vectors suitable
for the FFT length and will be processed in parallel. Figure <a
href="#fig:ofdm_carr_alloc" data-reference-type="ref"
data-reference="fig:ofdm_carr_alloc">[fig:ofdm_carr_alloc]</a> shows the
parameters of this block. Variables are used in complex GNU Radio
applications to have common parameters among blocks. In this case
<em>occupied_carriers, pilot_carriers, pilot_symbols</em> etc. are
variables defined in the flowgraph in a separate block. It is possible
to configure these and have different number of carriers or pilot
signals.</p>
<p>In the second block, <em>FFT</em>, IFFT is performed as it can be
seen from the <em>Forward/Reverse</em> switch. Finally in the third
block, <em>OFDM Cyclic Prefixer</em>, adds cyclic prefix to the
carriers. The resulting signal is feed into <em>UHD: USRP Sink</em>
block to send the signal from host computer to the connected SDR and to
transmit it.</p>
<p>It is important to configure the USRP to have successful
communication, the parameters of the project’s USRP is shown in Figure
<a href="#fig:usrp_settings" data-reference-type="ref"
data-reference="fig:usrp_settings">7</a>. Gain should be selected
carefully as too much gain can cause harmonics and too low can cause the
signal to have lower reception. In addition, center frequency and the
channel bandwidth should be selected by considering transmitter
antenna.</p>
<figure id="fig:usrp_settings">
<img src="./Figures/Figures/ofdm_carrier_all.png" title="fig:" />
<img src="./Figures/Figures/USRP_rfoptions.png" title="fig:" />
<figcaption>USRP settings used.</figcaption>
</figure>
<p>The constellation of the transmitted signal is shown in Figure <a
href="#fig:constell" data-reference-type="ref"
data-reference="fig:constell">8</a>. Because the signal is in time
domain the constellation does not have distinction in distribution. The
frequency spectrum of the transmitted signal is shown in Figure <a
href="#fig:tx_freq" data-reference-type="ref"
data-reference="fig:tx_freq">9</a>. The transmitted band can be clearly
differentiated from the ends of the spectrum.</p>
<figure id="fig:constell">
<img src="./Figures/Figures/Transmitted_signal_const.png" title="fig:"
style="width:70.0%" />
<figcaption>Constellation of transmitted signal.</figcaption>
</figure>
<figure id="fig:tx_freq">
<img src="./Figures/Figures/Transmitted_signal_freq_spec.png"
title="fig:" style="width:100.0%" />
<figcaption>Transmitted signal frequency spectrum.</figcaption>
</figure>
<h2 id="ofdm-receiver">OFDM Receiver</h2>
<p>In this section, OFDM receiver structure in GNU Radio will be
described.</p>
<p>The received signal from receiver USRP is forwarded to GNURadio
interface with the help of <em>UHD: USRP Source</em> block, it is shown
in Figure <a href="#fig:schmid" data-reference-type="ref"
data-reference="fig:schmid">10</a>. The center frequency and the channel
bandwidth should be selected same as the transmitted side to have better
performance. Gain value should be adjusted carrefully to avoid the noise
enhencement. The adjustable channel model block can be placed to see the
effect of the channel on the received signal. After the <em>Channel
Model</em> block, starting time instant of the frame is determined
according to the Schmidl &amp; Cox’s method in the <em>Schmidl &amp; Cox
OFDM synch.</em> block. Also, fine frequency offset is calculated in the
same block. The calculated frequency offset is removed after
<em>Frequency Mod</em> block.</p>
<figure id="fig:schmid">
<img src="./Figures/Figures/Rx_usrp_schmidl.png" title="fig:"
style="width:90.0%" />
<figcaption>Schmidl &amp; Cox Synchronization system in OFDM
receiver.</figcaption>
</figure>
<p>The constellation diagram of the received signal can be seen in
Figure <a href="#fig:constell_rx_presynch" data-reference-type="ref"
data-reference="fig:constell_rx_presynch">11</a>. Since this diagram is
obtained after the channel, frequency offset effect can be seen easily.
If the pattern of the constellation diagram is like a square, it can be
said that, there is no frequency offset. However, because of the pattern
of the diagram is like a disk, existence of the frequency offset can be
noticed.</p>
<figure id="fig:constell_rx_presynch">
<img src="./Figures/Figures/Received_signal_before_sync.png"
title="fig:" style="width:70.0%" />
<figcaption>Constellation of received signal before
synchronization.</figcaption>
</figure>
<p>The frequency spectrum of the received signal is shown in the Figure
<a href="#fig:freq_rx" data-reference-type="ref"
data-reference="fig:freq_rx">12</a>. Since the channel bandwidth is
adjusted to 15 MHz, the received signal band can be seen 15 MHz around
the center frequency.</p>
<figure id="fig:freq_rx">
<img src="./Figures/Figures/Received_signal_freq_spec.png" title="fig:"
style="width:100.0%" />
<figcaption>Frequency spectrum of received signal.</figcaption>
</figure>
<figure id="fig:demux">
<img src="./Figures/Figures/Header_payload_demux.png" title="fig:"
style="width:120.0%" />
<figcaption>Header and Payload Demux in OFDM receiver.</figcaption>
</figure>
<p>After the synchronization steps, the header bits and the payload bits
are splitted by using the <em>Header/Payload Demux</em> block. This
block works as a feedback system. It uses the synchronized data and
splits the header and payload data by using demodulated header data.</p>
<p>Now, the header stream is in time domain. Forward FFT is applied to
analyze and demodulate the OFDM signal. Also, this stream is converted
to the parallel streams in the <em>FFT</em> block. Next, the channel is
estimated by using synchronization words which are the same as with
trasnmitted side. The <em>ofdm_sync_carr_taps</em> information is
obtained with the help of this block. Then, at the <em>OFDM Frame
Equalizer</em> block, the phase and time offsets are eliminated and the
channel effect is removed by the equalization formula below <span
class="citation" data-cites="ofdm_website"></span>,</p>
<p><span class="math display">$$\alpha * H[k] + (1-\alpha) * \frac{s_{i,
k}}{p_j}$$</span></p>
<p>where <span class="math inline"><em>H</em></span> is the channel
response in the frequency domain, <span
class="math inline"><em>s</em><sub><em>i</em>, <em>k</em></sub></span>
is the received signal, <span
class="math inline"><em>p</em><sub><em>j</em></sub></span> is the
inserted pilot symbol and <span class="math inline"><em>α</em></span> is
the constant which is equal to <span class="math inline">0.1</span>.</p>
<figure id="fig:ch_est_ofdm">
<img src="./Figures/Figures/ofdm_chan_est.png" title="fig:"
style="width:70.0%" />
<figcaption>OFDM channel estimation parameters.</figcaption>
</figure>
<figure id="fig:ofdm_rx">
<img src="./Figures/Figures/Rx_ofdm.png" title="fig:"
style="width:70.0%" />
<figcaption>OFDM receiver system.</figcaption>
</figure>
<p>The received data is processed by demodulating and removing CRC as
shown in Figure <a href="#fig:qpsk_rx" data-reference-type="ref"
data-reference="fig:qpsk_rx">16</a>. Constellation of the demodulated
data is shown in Figure <a href="#fig:constell_rx"
data-reference-type="ref" data-reference="fig:constell_rx">17</a>. When
compared to Figure <a href="#fig:constell_tx" data-reference-type="ref"
data-reference="fig:constell_tx">5</a>, BPSK constellation is not
visible because here the constellation is observed after demuxing the
header and payload data streams.</p>
<figure id="fig:qpsk_rx">
<img src="./Figures/Figures/Rx_qpsk_crc_demod.png" title="fig:"
style="width:80.0%" />
<figcaption>CRC removal and QPSK demodulation in receiver.</figcaption>
</figure>
<figure id="fig:constell_rx">
<img src="./Figures/Figures/Demodulated_data.png" title="fig:"
style="width:70.0%" />
<figcaption>Constellation of demodulated data in OFDM
receiver.</figcaption>
</figure>
<p>The received data is appended to a file when the system is running.
<em>File Sink</em> settings is shown in Figure <a
href="#fig:file_sink_sett" data-reference-type="ref"
data-reference="fig:file_sink_sett">[fig:file_sink_sett]</a> which is
similar to <em>File Source</em>. Path and input type can be configured.
Select buffered option to buffer the incoming data in memory before
writing to file if I/O is causing a problem. The received data can be
seen in Figure <a href="#fig:data_out" data-reference-type="ref"
data-reference="fig:data_out">18</a>. Notice contrary to most, some data
is lost. Error can be calculated by comparing the input file and the
data received.</p>
<figure id="fig:data_out">
<img src="./Figures/Figures/file_sink.png" title="fig:" />
<img src="./Figures/Figures/received_data_txt.png" title="fig:"
style="width:90.0%" />
<figcaption>Text output of received data.</figcaption>
</figure>
<h2 id="mrc-blocks">MRC Blocks</h2>
<p>After implementing OFDM transceiver, a MISO system is investigated as
the first step towards a MIMO system. A system with a single transmitter
and multiple receivers was designed in GNU Radio Companion and with
physical SDR devices. Maximum Ratio Combining (MRC), which was also
discussed in Section <a href="#sec:mrc" data-reference-type="ref"
data-reference="sec:mrc">2.2.1</a>, was implemented. MRC requires
channel tap information in the algorithm which <em>OFDM Channel
Estimation</em> block provides. A <em>Tag Gate</em> block is used to
isolate the channel tap tag information from the rest of tags as shown
in Figure <a href="#fig:channel_system" data-reference-type="ref"
data-reference="fig:channel_system">19</a>.</p>
<figure id="fig:channel_system">
<img src="./Figures/Figures/channel_info.png" title="fig:"
style="width:70.0%" />
<figcaption>Channel system.</figcaption>
</figure>
<p>The custom MRC block was designed as a <em>Hier Block</em> as shown
in Figure <a href="#fig:mrc" data-reference-type="ref"
data-reference="fig:mrc">20</a> which is a flowgraph that can be
imported to other flowgraphs in a single block. The algorithm is
implemented using built-in computation blocks. Due to crashes we had
while working real-time, offline analysis is performed in the Figure.
Received data and channel taps are feed to the system which were
collected from a real time operation.</p>
<figure id="fig:mrc">
<img src="./Figures/Figures/file_read_mrc.png" title="fig:"
style="width:110.0%" />
<figcaption>MRC hierarchy block.</figcaption>
</figure>
</body>
</html>
