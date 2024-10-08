## Copyright (C) 2024 Randall Samuel Mendez Loria
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## listen_filter: carga un audio.wav y aplica el filtro.mat
##
## Uso:
## listen_filter('filtro.mat', 'audio.wav', fs_target)
##
## filter_file: Nombre del archivo .mat que contiene el filtro.
## audio_file: Nombre del archivo .wav a filtrar.
## fs_target: Frecuencia de muestreo a utilizar (por defecto 48000 Hz).

function listen_filter(filter_file, audio_file, fs_target = 48000)

    # Carga el archivo.mat
    data = load(filter_file, "SOS");

    # Recostruye el filtro de grado 3
    [b, a] = sos2tf(data.SOS);

    # Carga el audio
    [y, fs_audio] = audioread(audio_file);

    # Revisa si la frecuencia de muestreo del audio, es igual a la frecuencia que se quiere.
    # Si no son iguales, modifica la frecuencia de muestreo a la frecuenciaq que se quiere.
    if fs_audio ~= fs_target
        y = resample(y, fs_target, fs_audio);
        fs_audio = fs_target;
    end

    # Aplica el filtro
    y_filtered = filter(b, a, y);

    # Hace sonar el audio filtrado
    sound(y_filtered, fs_target);

    # pkg load signal;
    # listen_filter("ellip_lowpass.mat", "../clips/frequency_sweep.wav")

endfunction
