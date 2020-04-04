const char* VERSION = "V1.0";
const float FILTERFREQS[128] = {20, 23, 26, 29, 32, 36, 40, 46, 53, 60, 69, 78, 87, 98, 109, 120, 132, 145, 157, 171, 186, 200, 215, 231, 247, 264, 282, 300, 319, 338, 357, 378, 399, 421, 444, 467, 491, 516, 541, 567, 594, 621, 650, 680, 710, 741, 774, 806, 841, 876, 912, 949, 987, 1027, 1068, 1110, 1152, 1196, 1242, 1290, 1338, 1388, 1439, 1491, 1547, 1603, 1661, 1723, 1783, 1843, 1915, 1975, 2047, 2119, 2191, 2263, 2347, 2419, 2503, 2587, 2683, 2767, 2863, 2959, 3055, 3163, 3259, 3367, 3487, 3595, 3715, 3835, 3967, 4099, 4231, 4363, 4507, 4663, 4807, 4963, 5131, 5287, 5467, 5635, 5815, 6007, 6199, 6403, 6607, 6823, 7039, 7267, 7495, 7735, 7987, 8239, 8503, 8779, 9055, 9343, 9643, 9955, 10267, 10603, 10939, 11287, 11647, 12000};
const float POWER[128] = {0, 0.00009, 0.0003, 0.0006, 0.001, 0.0016, 0.0022, 0.003, 0.004, 0.005, 0.0062, 0.0075, 0.0089, 0.0105, 0.0122, 0.014, 0.016, 0.018, 0.02, 0.022, 0.025, 0.027, 0.03, 0.033, 0.036, 0.039, 0.042, 0.045, 0.049, 0.052, 0.056, 0.06, 0.063, 0.068, 0.072, 0.076, 0.08, 0.085, 0.09, 0.094, 0.099, 0.104, 0.109, 0.115, 0.12, 0.126, 0.131, 0.137, 0.143, 0.149, 0.155, 0.161, 0.168, 0.174, 0.181, 0.188, 0.194, 0.201, 0.209, 0.216, 0.223, 0.231, 0.238, 0.246, 0.254, 0.262, 0.27, 0.278, 0.287, 0.295, 0.304, 0.313, 0.321, 0.33, 0.34, 0.349, 0.358, 0.368, 0.377, 0.387, 0.397, 0.407, 0.417, 0.427, 0.437, 0.448, 0.459, 0.469, 0.48, 0.491, 0.502, 0.513, 0.525, 0.536, 0.548, 0.56, 0.571, 0.583, 0.595, 0.608, 0.62, 0.632, 0.645, 0.658, 0.671, 0.684, 0.697, 0.71, 0.723, 0.737, 0.75, 0.764, 0.778, 0.792, 0.806, 0.82, 0.834, 0.849, 0.863, 0.878, 0.893, 0.908, 0.923, 0.938, 0.953, 0.969, 0.984, 1};
const float NOTEFREQS[128] = {8.176, 8.662, 9.177, 9.723, 10.301, 10.913, 11.562, 12.25, 12.978, 13.75, 14.568, 15.434, 16.352, 17.324, 18.354, 19.445, 20.602, 21.827, 23.125, 24.5, 25.957, 27.5, 29.135, 30.868, 32.703, 34.648, 36.708, 38.891, 41.203, 43.654, 46.249, 48.999, 51.913, 55, 58.27, 61.735, 65.406, 69.296, 73.416, 77.782, 82.407, 87.307, 92.499, 97.999, 103.826, 110, 116.541, 123.471, 130.813, 138.591, 146.832, 155.563, 164.814, 174.614, 184.997, 195.998, 207.652, 220, 233.082, 246.942, 261.626, 277.183, 293.665, 311.127, 329.628, 349.228, 369.994, 391.995, 415.305, 440, 466.164, 493.883, 523.251, 554.365, 587.33, 622.254, 659.255, 698.456, 739.989, 783.991, 830.609, 880, 932.328, 987.767, 1046.502, 1108.731, 1174.659, 1244.508, 1318.51, 1396.913, 1479.978, 1567.982, 1661.219, 1760, 1864.655, 1975.533, 2093.005, 2217.461, 2349.318, 2489.016, 2637.02, 2793.826, 2959.955, 3135.963, 3322.438, 3520, 3729.31, 3951.066, 4186.009, 4434.922, 4698.636, 4978.032, 5274.041, 5587.652, 5919.911, 6271.927, 6644.875, 7040, 7458.62, 7902.133, 8372.018, 8869.844, 9397.273, 9956.063, 10548.08, 11175.3, 11839.82, 12543.85};
const float ENVTIMES[128] = {1, 2, 4, 6, 9, 14, 20, 26, 33, 41, 49, 58, 67, 78, 89, 99, 111, 124, 136, 150, 164, 178, 192, 209, 224, 241, 258, 276, 295, 314, 333, 353, 374, 395, 418, 440, 464, 489, 513, 539, 565, 592, 621, 650, 680, 710, 742, 774, 808, 843, 878, 915, 952, 991, 1031, 1073, 1114, 1158, 1202, 1250, 1297, 1346, 1396, 1448, 1502, 1558, 1614, 1676, 1735, 1794, 1864, 1923, 1994, 2065, 2136, 2207, 2289, 2360, 2443, 2525, 2620, 2702, 2797, 2891, 2985, 3092, 3186, 3292, 3410, 3516, 3634, 3752, 3882, 4012, 4142, 4272, 4413, 4567, 4708, 4862, 5027, 5180, 5357, 5522, 5699, 5888, 6077, 6278, 6478, 6691, 6903, 7127, 7351, 7587, 7835, 8083, 8343, 8614, 8885, 9169, 9464, 9770, 10077, 10408, 10738, 11080, 11434, 11700};
const float LFOTEMPO[128] = {8, 8, 8, 8, 8, 8, 8, 8, 6, 6, 6, 6, 6, 6, 6, 6, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1.5, 1, 1, 1, 1, 1, 1, 1, 1, 0.75, 0.75, 0.75, 0.75, 0.75, 0.75, 0.75, 0.75, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.333, 0.333, 0.333, 0.333, 0.333, 0.333, 0.333, 0.333, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, 0.167, 0.167, 0.167, 0.167, 0.167, 0.167, 0.167, 0.167, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.125, 0.083, 0.083, 0.083, 0.083, 0.083, 0.083, 0.083, 0.083, 0.063, 0.063, 0.063, 0.063, 0.063, 0.063, 0.063, 0.063, 0.047, 0.047, 0.047, 0.047, 0.047, 0.047, 0.047, 0.047};
const String LFOTEMPOSTR[128] = {"1/32", "1/32", "1/32", "1/32", "1/32", "1/32", "1/32", "1/32", "3/64", "3/64", "3/64", "3/64", "3/64", "3/64", "3/64", "3/64", "1/16", "1/16", "1/16", "1/16", "1/16", "1/16", "1/16", "1/16", "3/32", "3/32", "3/32", "3/32", "3/32", "3/32", "3/32", "3/32", "1/8", "1/8", "1/8", "1/8", "1/8", "1/8", "1/8", "1/8", "3/16", "3/16", "3/16", "3/16", "3/16", "3/16", "3/16", "3/16", "1/4", "1/4", "1/4", "1/4", "1/4", "1/4", "1/4", "1/4", "3/8", "3/8", "3/8", "3/8", "3/8", "3/8", "3/8", "3/8", "1/2", "1/2", "1/2", "1/2", "1/2", "1/2", "1/2", "1/2", "3/4", "3/4", "3/4", "3/4", "3/4", "3/4", "3/4", "3/4", "1", "1", "1", "1", "1", "1", "1", "1", "3/2", "3/2", "3/2", "3/2", "3/2", "3/2", "3/2", "3/2", "2", "2", "2", "2", "2", "2", "2", "2", "3", "3", "3", "3", "3", "3", "3", "3", "4", "4", "4", "4", "4", "4", "4", "4", "6", "6", "6", "6", "6", "6", "6", "6"};
const float OSCMIXA[128] = {127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 125, 123, 120, 118, 116, 114, 112, 110, 108, 106, 104, 102, 100, 98, 96, 94, 92, 90, 88, 86, 84, 82, 80, 78, 76, 74, 72, 70, 68, 66, 64, 62, 60, 58, 56, 54, 52, 50, 48, 46, 44, 42, 40, 38, 36, 34, 32, 30, 28, 26, 24, 22, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 0};
const float OSCMIXB[128] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 123, 125, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127};
const float OCTAVECONTROL[128] = { -24, -24, -24, -24, -24, -12, -12, -12, -12, -12, -11, -11, -11, -11, -11, -10, -10, -10, -10, -9, -9, -9, -9, -9, -8, -8, -8, -8, -8, -7, -7, -7, -7, -7, -6, -6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 12, 24, 24, 24, 24, 24};
const float KEYTRACKINGAMT[128] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1};
#define DIV8192 (1.0f / 8192.0f)//For pitchbend
#define DIV127 (1.0f / 127.0f)
#define DIV12 (1.0f / 12.0f)
const float LINEAR[128] = {0, 0.008, 0.016, 0.024, 0.031, 0.039, 0.047, 0.055, 0.063, 0.071, 0.079, 0.087, 0.094, 0.102, 0.11, 0.118, 0.126, 0.134, 0.142, 0.15, 0.157, 0.165, 0.173, 0.181, 0.189, 0.197, 0.205, 0.213, 0.22, 0.228, 0.236, 0.244, 0.252, 0.26, 0.268, 0.276, 0.283, 0.291, 0.299, 0.307, 0.315, 0.323, 0.331, 0.339, 0.346, 0.354, 0.362, 0.37, 0.378, 0.386, 0.394, 0.402, 0.409, 0.417, 0.425, 0.433, 0.441, 0.449, 0.457, 0.465, 0.472, 0.48, 0.488, 0.496, 0.504, 0.512, 0.52, 0.528, 0.535, 0.543, 0.551, 0.559, 0.567, 0.575, 0.583, 0.591, 0.598, 0.606, 0.614, 0.622, 0.63, 0.638, 0.646, 0.654, 0.661, 0.669, 0.677, 0.685, 0.693, 0.701, 0.709, 0.717, 0.724, 0.732, 0.74, 0.748, 0.756, 0.764, 0.772, 0.78, 0.787, 0.795, 0.803, 0.811, 0.819, 0.827, 0.835, 0.843, 0.85, 0.858, 0.866, 0.874, 0.882, 0.89, 0.898, 0.906, 0.913, 0.921, 0.929, 0.937, 0.945, 0.953, 0.961, 0.969, 0.976, 0.984, 0.992, 1.00};
const float LINEARCENTREZERO[128] = { -1, -0.98, -0.97, -0.95, -0.93, -0.92, -0.9, -0.88, -0.87, -0.85, -0.83, -0.82, -0.8, -0.78, -0.77, -0.75, -0.73, -0.72, -0.7, -0.68, -0.67, -0.65, -0.63, -0.62, -0.6, -0.58, -0.57, -0.55, -0.53, -0.52, -0.5, -0.48, -0.47, -0.45, -0.43, -0.42, -0.4, -0.38, -0.37, -0.35, -0.33, -0.32, -0.3, -0.28, -0.27, -0.25, -0.23, -0.22, -0.2, -0.18, -0.17, -0.15, -0.13, -0.12, -0.1, -0.08, -0.07, -0.05, -0.03, -0.02, -0.01, 0, 0, 0, 0, 0, 0, 0.01, 0.02, 0.03, 0.05, 0.07, 0.08, 0.1, 0.12, 0.13, 0.15, 0.17, 0.18, 0.2, 0.22, 0.23, 0.25, 0.27, 0.28, 0.3, 0.32, 0.33, 0.35, 0.37, 0.38, 0.4, 0.42, 0.43, 0.45, 0.47, 0.48, 0.5, 0.52, 0.53, 0.55, 0.57, 0.58, 0.6, 0.62, 0.63, 0.65, 0.67, 0.68, 0.7, 0.72, 0.73, 0.75, 0.77, 0.78, 0.8, 0.82, 0.83, 0.85, 0.87, 0.88, 0.9, 0.92, 0.93, 0.95, 0.97, 0.98, 1};
const float LINEAR_FILTERMIXER[128] = {0, 0.008, 0.016, 0.024, 0.031, 0.039, 0.047, 0.055, 0.063, 0.071, 0.079, 0.087, 0.094, 0.102, 0.11, 0.118, 0.126, 0.134, 0.142, 0.15, 0.157, 0.165, 0.173, 0.181, 0.189, 0.197, 0.205, 0.213, 0.22, 0.228, 0.236, 0.244, 0.252, 0.26, 0.268, 0.276, 0.283, 0.291, 0.299, 0.307, 0.315, 0.323, 0.331, 0.339, 0.346, 0.354, 0.362, 0.37, 0.378, 0.386, 0.394, 0.402, 0.409, 0.417, 0.425, 0.433, 0.441, 0.449, 0.457, 0.465, 0.472, 0.48, 0.488, 0.496, 0.504, 0.512, 0.52, 0.528, 0.535, 0.543, 0.551, 0.559, 0.567, 0.575, 0.583, 0.591, 0.598, 0.606, 0.614, 0.622, 0.63, 0.638, 0.646, 0.654, 0.661, 0.669, 0.677, 0.685, 0.693, 0.701, 0.709, 0.717, 0.724, 0.732, 0.74, 0.748, 0.756, 0.764, 0.772, 0.78, 0.787, 0.795, 0.803, 0.811, 0.819, 0.827, 0.835, 0.843, 0.85, 0.858, 0.866, 0.874, 0.882, 0.89, 0.898, 0.906, 0.913, 0.921, 0.929, 0.937, 0.945, 0.953, 0.961, 0.976, 0.988, 1.0, -99, -99};//{LP...HP,BP,BP}
const int LINEAR_FILTERMIXERSTR[128] = {0, 1, 2, 2, 3, 4, 5, 6, 6, 7, 8, 9, 9, 10, 11, 12, 13, 13, 14, 15, 16, 17, 17, 18, 19, 20, 20, 21, 22, 23, 24, 24, 25, 26, 27, 28, 28, 29, 30, 31, 31, 32, 33, 34, 35, 35, 36, 37, 38, 39, 39, 40, 41, 42, 43, 43, 44, 45, 46, 46, 47, 48, 49, 50, 50, 51, 52, 53, 54, 54, 55, 56, 57, 57, 58, 59, 60, 61, 61, 62, 63, 64, 65, 65, 66, 67, 68, 69, 69, 70, 71, 72, 72, 73, 74, 75, 76, 76, 77, 78, 79, 80, 80, 81, 82, 83, 83, 84, 85, 86, 87, 87, 88, 89, 90, 91, 91, 92, 93, 94, 94, 95, 96, 97, 98, 99, 100, 100};
const int16_t PARABOLIC_WAVE[256] = { -28000, -27310, -26620, -25931, -25241, -24553, -23864, -23177, -22490, -21803, -21118, -20434, -19751, -19069, -18389, -17710, -17033, -16357, -15683, -15011, -14341, -13673, -13007, -12343, -11682, -11023, -10367, -9714, -9063, -8415, -7770, -7129, -6490, -5855, -5223, -4594, -3969, -3348, -2730, -2117, -1507, -901, -299, 298, 891, 1480, 2065, 2644, 3219, 3790, 4355, 4916, 5472, 6022, 6568, 7108, 7643, 8172, 8696, 9214, 9727, 10234, 10735, 11230, 11720, 12203, 12680, 13151, 13616, 14075, 14527, 14972, 15411, 15844, 16270, 16689, 17101, 17507, 17905, 18297, 18682, 19059, 19430, 19793, 20149, 20497, 20839, 21173, 21499, 21818, 22129, 22433, 22729, 23017, 23298, 23571, 23836, 24093, 24342, 24583, 24817, 25042, 25259, 25468, 25669, 25862, 26047, 26223, 26392, 26552, 26704, 26847, 26982, 27109, 27227, 27337, 27439, 27532, 27617, 27693, 27761, 27821, 27871, 27914, 27948, 27973, 27990, 27999, 27999, 27990, 27973, 27948, 27914, 27871, 27821, 27761, 27693, 27617, 27532, 27439, 27337, 27227, 27109, 26982, 26847, 26704, 26552, 26392, 26223, 26047, 25862, 25669, 25468, 25259, 25042, 24817, 24583, 24342, 24093, 23836, 23571, 23298, 23017, 22729, 22433, 22129, 21818, 21499, 21173, 20839, 20497, 20149, 19793, 19430, 19059, 18682, 18297, 17905, 17507, 17101, 16689, 16270, 15844, 15411, 14972, 14527, 14075, 13616, 13151, 12680, 12203, 11720, 11230, 10735, 10234, 9727, 9214, 8696, 8172, 7643, 7108, 6568, 6022, 5472, 4916, 4355, 3790, 3219, 2644, 2065, 1480, 891, 298, -299, -901, -1507, -2117, -2730, -3348, -3969, -4594, -5223, -5855, -6490, -7129, -7770, -8415, -9063, -9714, -10367, -11023, -11682, -12343, -13007, -13673, -14341, -15011, -15683, -16357, -17033, -17710, -18389, -19069, -19751, -20434, -21118, -21803, -22490, -23177, -23864, -24553, -25241, -25931, -26620, -27310, -28000};
const int16_t HARMONIC_WAVE[256] = { 0, 3934, 7773, 11428, 14813, 17853, 20484, 22655, 24332, 25493, 26137, 26276, 25937, 25162, 24004, 22525, 20793, 18882, 16865, 14816, 12801, 10882, 9113, 7536, 6183, 5074, 4218, 3612, 3244, 3092, 3127, 3314, 3617, 3996, 4414, 4834, 5226, 5563, 5826, 6003, 6087, 6082, 5994, 5838, 5631, 5395, 5151, 4923, 4732, 4595, 4527, 4538, 4633, 4808, 5059, 5372, 5730, 6113, 6497, 6858, 7171, 7413, 7564, 7606, 7529, 7325, 6993, 6539, 5974, 5314, 4581, 3797, 2992, 2191, 1423, 714, 87, -440, -852, -1141, -1303, -1344, -1271, -1101, -851, -546, -209, 132, 451, 724, 929, 1048, 1067, 980, 783, 482, 85, -393, -932, -1511, -2104, -2685, -3228, -3710, -4109, -4407, -4592, -4655, -4595, -4415, -4124, -3736, -3270, -2747, -2192, -1628, -1080, -571, -122, 252, 537, 727, 820, 819, 735, 579, 370, 127, -127, -370, -579, -735, -819, -820, -727, -537, -252, 122, 571, 1080, 1628, 2192, 2747, 3270, 3736, 4124, 4415, 4595, 4655, 4592, 4407, 4109, 3710, 3228, 2685, 2104, 1511, 932, 393, -85, -482, -783, -980, -1067, -1048, -929, -724, -451, -132, 209, 546, 851, 1101, 1271, 1344, 1303, 1141, 852, 440, -87, -714, -1423, -2191, -2992, -3797, -4581, -5314, -5974, -6539, -6993, -7325, -7529, -7606, -7564, -7413, -7171, -6858, -6497, -6113, -5730, -5372, -5059, -4808, -4633, -4538, -4527, -4595, -4732, -4923, -5151, -5395, -5631, -5838, -5994, -6082, -6087, -6003, -5826, -5563, -5226, -4834, -4414, -3996, -3617, -3314, -3127, -3092, -3244, -3612, -4218, -5074, -6183, -7536, -9113, -10882, -12801, -14816, -16865, -18882, -20793, -22525, -24004, -25162, -25937, -26276, -26137, -25493, -24332, -22655, -20484, -17853, -14813, -11428, -7773, -3934, 0};
const int16_t PPG_WAVE[256] = {455, 4257, 12654, 21524, 27042, 29297, 30527, 30599, 28691, 25352, 22613, 20841, 19570, 18729, 19317, 21097, 23149, 24638, 25735, 26000, 24846, 21902, 17751, 12607, 6711, 399, -5419, -10409, -14393, -17262, -18601, -18616, -17616, -15827, -13201, -10328, -7929, -6346, -5257, -4661, -4831, -5865, -7209, -8331, -9023, -9326, -9135, -8295, -6692, -4347, -1469, 1531, 4149, 5977, 6679, 6172, 4685, 2771, 785, -1134, -3014, -4655, -5872, -6344, -5928, -4655, -3053, -1457, 104, 1848, 3452, 4607, 5265, 5768, 5967, 5738, 5238, 5046, 5120, 5251, 5386, 5936, 6781, 7676, 8446, 9285, 9879, 9979, 9593, 9073, 8135, 6588, 4663, 2955, 1254, -665, -2465, -3371, -3660, -3996, -4518, -4612, -4385, -4300, -4440, -4253, -3895, -3830, -4099, -4091, -3857, -3754, -3768, -3370, -2749, -2310, -1941, -1073, -66, 429, 542, 1154, 2163, 2759, 2616, 2285, 1759, 648, -904, -2015, -2541, -2872, -3015, -2419, -1410, -798, -685, -190, 817, 1685, 2054, 2493, 3114, 3512, 3498, 3601, 3835, 3843, 3574, 3639, 3997, 4184, 4044, 4129, 4356, 4262, 3740, 3404, 3115, 2209, 409, -1510, -3211, -4919, -6844, -8391, -9329, -9849, -10235, -10135, -9541, -8702, -7932, -7037, -6192, -5642, -5507, -5376, -5302, -5494, -5994, -6223, -6024, -5521, -4863, -3708, -2104, -360, 1201, 2797, 4399, 5672, 6088, 5616, 4399, 2758, 878, -1041, -3027, -4941, -6428, -6935, -6233, -4405, -1787, 1213, 4091, 6436, 8039, 8879, 9070, 8767, 8075, 6953, 5609, 4575, 4405, 5001, 6090, 7673, 10072, 12945, 15571, 17360, 18360, 18345, 17006, 14137, 10153, 5163, -655, -6966, -12863, -18007, -22158, -25102, -26256, -25991, -24894, -23405, -21353, -19573, -18985, -19826, -21097, -22869, -25608, -28947, -19538, -22187, -22187, -22383, -22054, -17988, -12202, 252};
#define AWFREQ 172.0f//Arbitrary waveform max frequency - NOT CURRENTLY USED
const float PWMRATE[128] = { -10, -10, -5, -5, -5, -5, -5, 0.02, 0.03, 0.05, 0.062, 0.075, 0.089, 0.105, 0.122, 0.14, 0.16, 0.18, 0.2, 0.22, 0.25, 0.27, 0.3, 0.33, 0.36, 0.39, 0.42, 0.45, 0.49, 0.52, 0.56, 0.6, 0.63, 0.68, 0.72, 0.76, 0.8, 0.85, 0.9, 0.94, 0.99, 1.04, 1.09, 1.15, 1.2, 1.26, 1.31, 1.37, 1.43, 1.49, 1.55, 1.61, 1.68, 1.74, 1.81, 1.88, 1.94, 2.01, 2.09, 2.16, 2.23, 2.31, 2.38, 2.46, 2.54, 2.62, 2.7, 2.78, 2.87, 2.95, 3.04, 3.13, 3.21, 3.3, 3.4, 3.49, 3.58, 3.68, 3.77, 3.87, 3.97, 4.07, 4.17, 4.27, 4.37, 4.48, 4.59, 4.69, 4.8, 4.91, 5.02, 5.13, 5.25, 5.36, 5.48, 5.6, 5.71, 5.83, 5.95, 6.08, 6.2, 6.32, 6.45, 6.58, 6.71, 6.84, 6.97, 7.1, 7.23, 7.37, 7.5, 7.64, 7.78, 7.92, 8.06, 8.2, 8.34, 8.49, 8.63, 8.78, 8.93, 9.08, 9.23, 9.38, 9.53, 9.69, 9.84, 10};
#define VCOLFOOCTAVERANGE 2.0f//2 Oct range
#define MAXDETUNE 0.04f //4%
#define PWMWAVEFORM WAVEFORM_SINE
#define LFOMAXRATE 40.0f//40Hz
#define PWMSOURCELFO 0
#define PWMSOURCEFENV 1
#define SGTL_MAXVOLUME 0.9f
#define VOICEMIXERLEVEL 0.33f
#define CONSTANTONE 1.0f
#define VCOMODMIXERMAX 1.0f
#define VCFMODMIXERMAX 1.0f
#define FILTEROCTAVERANGE 7.0f
#define GLIDEFACTOR 1000.0f//Maximum time in milliseconds limited by precision
#define  NO_OF_VOICES 6
#define NO_OF_PARAMS 47
const char* INITPATCHNAME = "Initial Patch";
#define HOLD_DURATION 1000
const float ENSEMBLE_LFO[128] = {0.2, 0.3, 0.5, 0.6, 0.8, 0.9, 1.1, 1.2, 1.4, 1.5, 1.7, 1.8, 2, 2.1, 2.3, 2.4, 2.6, 2.7, 2.9, 3, 3.2, 3.3, 3.5, 3.6, 3.8, 3.9, 4.1, 4.2, 4.4, 4.5, 4.7, 4.8, 5, 5.1, 5.3, 5.4, 5.6, 5.7, 5.9, 6, 6.2, 6.3, 6.5, 6.6, 6.8, 6.9, 7.1, 7.2, 7.4, 7.5, 7.7, 7.8, 8, 8.1, 8.3, 8.4, 8.6, 8.7, 8.9, 9, 9.2, 9.3, 9.5, 9.6, 9.8, 9.9, 10.1, 10.2, 10.4, 10.5, 10.7, 10.8, 11, 11.1, 11.3, 11.4, 11.6, 11.7, 11.9, 12, 12.2, 12.3, 12.5, 12.6, 12.8, 12.9, 13.1, 13.2, 13.4, 13.5, 13.7, 13.8, 14, 14.1, 14.3, 14.4, 14.6, 14.7, 14.9, 15, 15.2, 15.3, 15.5, 15.6, 15.8, 15.9, 16.1, 16.2, 16.4, 16.5, 16.7, 16.8, 17, 17.1, 17.3, 17.4, 17.6, 17.7, 17.9, 18, 18.2, 18.3, 18.5, 18.6, 18.8, 18.9, 19.1, 20};
#define PATCHES_LIMIT 999
const String INITPATCH = "Solina,1.00,1.00,0.00,0,1,1.00,1.00,0.00,1.00,0.47,0.00,0,-12,5,8,0,0.94,1.00,0.80,0.00,0.00,5.00,300.00,0.00,0.70,0.00,7.24,0,0,0,10.48,0,0,0.00,1,4.00,2985.00,0.32,1864.00,33.00,808.00,0.92,1250.00,5.10,0.74,0";
