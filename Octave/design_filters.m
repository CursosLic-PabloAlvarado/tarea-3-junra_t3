## Copyright 2024 Juan Pablo Rodríguez Cano, Randall Samuel Mendez Loria
## Diseño de filtros de la tarea 3.
## EL5805 Procesamiento digital de señales

## desing_filters : Encargado de diseñar los filtros

pkg load signal;

order = 3;

# dB
r_bp = 1;
a_br = 50;

# Freciencias de cortes para los filtros
f_Fpb = 440;
f_Fpa = 600;
f_Fpb_i = 220;
f_Fpb_s = 1000;
f_Fsb_i = 220;
f_Fsb_s = 1000;

#frecuencia de muestreo y señales
Fs = 48000;
Fs2 = Fs/2;

# ellip
# Low Pass Filter
[b, a] = ellip (order, r_bp, a_br, f_Fpb/Fs2);
SOS = tf2sos(b, a);
save("ellip_lowpass.mat", "SOS");

# High Pass Filter
[b, a] = ellip (order, r_bp, a_br, f_Fpa/Fs2, 'high');
SOS = tf2sos(b, a);
save("ellip_highpass.mat", "SOS");

# Band Pass Filter
[b, a] = ellip (order, r_bp, a_br, [f_Fpb_i f_Fpb_s]/Fs2);
SOS = tf2sos(b, a);
save("ellip_bandpass.mat", "SOS");

# Band Reject Reject
[b, a] = ellip (order, r_bp, a_br, [f_Fsb_i f_Fsb_s]/Fs2, 'stop');
SOS = tf2sos(b, a);
save("ellip_bandstop.mat", "SOS");


# butter
[b,a]=butter ( 3, f_Fpb / Fs2, 'low'); # Low Pass Filter
SOS = tf2sos(b, a);
save("butter_lowpass.mat", "SOS");

[b,a]=butter ( 3, f_Fpa / Fs2, 'high');# High Pass Filter
SOS = tf2sos(b, a);
save("butter_highpass.mat", "SOS");

[b,a]=butter ( 3, [f_Fpb_i, f_Fpb_s]/Fs2, 'bandpass');# Band Pass Filter
SOS = tf2sos(b, a);
save("butter_bandpass.mat", "SOS");

[b,a]=butter ( 3, [f_Fsb_i, f_Fsb_s]/Fs2, 'stop');# Band Reject Reject
SOS = tf2sos(b, a);
save("butter_bandstop.mat", "SOS");


# cheby1
# Low Pass Filter
[b, a] = cheby1 (order, r_bp, f_Fpb/Fs2);
SOS = tf2sos(b, a);
save("cheby1_lowpass.mat", "SOS");

# High Pass Filter
[b, a] = cheby1 (order, r_bp, f_Fpa/Fs2, 'high');
SOS = tf2sos(b, a);
save("cheby1_highpass.mat", "SOS");

# Band Pass Filter
[b, a] = cheby1 (order, r_bp, [f_Fpb_i f_Fpb_s]/Fs2);
SOS = tf2sos(b, a);
save("cheby1_bandpass.mat", "SOS");

# Band Reject Reject
[b, a] = cheby1 (order, r_bp, [f_Fsb_i f_Fsb_s]/Fs2, 'stop');
SOS = tf2sos(b, a);
save("cheby1_bandstop.mat", "SOS");


# cheby2
[b, a] = cheby2(3, a_br, f_Fpb/Fs2, 'low'); # Low Pass Filter
SOS = tf2sos(b, a);
save("cheby2_lowpass.mat", "SOS");

[b, a] = cheby2(3, a_br, f_Fpa/Fs2, 'high');# High Pass Filter
SOS = tf2sos(b, a);
save("cheby2_highpass.mat", "SOS");

[b, a] = cheby2(3, a_br, [f_Fpb_i f_Fpb_s]/Fs2);# Band Pass Filter
SOS = tf2sos(b, a);
save("cheby2_bandpass.mat", "SOS");

[b, a] = cheby2(3, a_br, [f_Fsb_i f_Fsb_s]/Fs2, 'stop');# Band Reject Reject
SOS = tf2sos(b, a);
save("cheby2_bandstop.mat", "SOS");
