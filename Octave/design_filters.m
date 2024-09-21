## Copyright 2024 Juan Pablo Rodríguez Cano, Randall Samuel Mendez Loria
## Diseño de filtros de la tarea 3.
## EL5805 Procesamiento digital de señales

## desing_filters : Encargado de diseñar los filtros

pkg load signal;

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
sf = 2000; sf2 = sf/2;
t = 0:1/sf:1;           % 1 second of time data
signal = sin(2*pi*50*t) + sin(2*pi*800*t);  % Mix of 50 Hz and 200 Hz

# ellip
# Low Pass Filter

# High Pass Filter

# Band Pass Filter

# Band Reject Reject


# butter
[b,a]=butter ( 3, f_Fpb / sf2, 'low'); # Low Pass Filter
[SOS, g] = tf2sos(b, a);
save("butter_lowpass.mat", "SOS");

[b,a]=butter ( 3, f_Fpa / sf2, 'high');# High Pass Filter
[SOS, g] = tf2sos(b, a);
save("butter_highpass.mat", "SOS");

[b,a]=butter ( 3, [f_Fpb_i/sf2, f_Fpb_s/sf2], 'bandpass');# Band Pass Filter
[SOS, g] = tf2sos(b, a);
save("butter_bandpass.mat", "SOS");

[b,a]=butter ( 3, [f_Fsb_i/sf2, f_Fsb_s/sf2], 'stop');# Band Reject Reject
[SOS, g] = tf2sos(b, a);
save("butter_bandstop.mat", "SOS");

# cheby1
# Low Pass Filter

# High Pass Filter

# Band Pass Filter

# Band Reject Reject


# cheby2
[b, a] = cheby2(3, 50, f_Fpb/sf2, 'low'); # Low Pass Filter
[SOS, g] = tf2sos(b, a);
save("cheby2_lowpass.mat", "SOS");

[b, a] = cheby2(3, 50, f_Fpa/sf2, 'high');# High Pass Filter
[SOS, g] = tf2sos(b, a);
save("cheby2_highpass.mat", "SOS");

[b, a] = cheby2(3, 50, [f_Fpb_i/sf2 f_Fpb_s/sf2]);# Band Pass Filter
[SOS, g] = tf2sos(b, a);
save("cheby2_bandpass.mat", "SOS");

[b, a] = cheby2(3, 50, [f_Fsb_i/sf2 f_Fsb_s/sf2], 'stop');# Band Reject Reject
[SOS, g] = tf2sos(b, a);
save("cheby2_bandstop.mat", "SOS");
