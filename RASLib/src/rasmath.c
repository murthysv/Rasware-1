#include "rasmath.h"
#include <math.h>

#define TABLESIZE 1000

float sinTable[TABLESIZE+1] = {0.000000, 0.006283, 0.012566, 0.018848, 0.025130, 0.031411, 0.037690, 0.043968, 0.050244, 0.056519, 0.062791, 0.069060, 0.075327, 0.081591, 0.087851, 0.094108, 0.100362, 0.106611, 0.112856, 0.119097, 0.125333, 0.131564, 0.137790, 0.144011, 0.150226, 0.156434, 0.162637, 0.168833, 0.175023, 0.181206, 0.187381, 0.193549, 0.199710, 0.205863, 0.212007, 0.218143, 0.224271, 0.230389, 0.236499, 0.242599, 0.248690, 0.254771, 0.260842, 0.266902, 0.272952, 0.278991, 0.285019, 0.291036, 0.297042, 0.303035, 0.309017, 0.314987, 0.320944, 0.326888, 0.332820, 0.338738, 0.344643, 0.350534, 0.356412, 0.362275, 0.368125, 0.373959, 0.379779, 0.385584, 0.391374, 0.397148, 0.402906, 0.408649, 0.414376, 0.420086, 0.425779, 0.431456, 0.437116, 0.442758, 0.448383, 0.453990, 0.459580, 0.465151, 0.470704, 0.476238, 0.481754, 0.487250, 0.492727, 0.498185, 0.503623, 0.509041, 0.514440, 0.519817, 0.525175, 0.530511, 0.535827, 0.541121, 0.546394, 0.551646, 0.556876, 0.562083, 0.567269, 0.572432, 0.577573, 0.582690, 0.587785, 0.592857, 0.597905, 0.602930, 0.607930, 0.612907, 0.617860, 0.622788, 0.627691, 0.632570, 0.637424, 0.642253, 0.647056, 0.651834, 0.656586, 0.661312, 0.666012, 0.670686, 0.675333, 0.679953, 0.684547, 0.689114, 0.693653, 0.698165, 0.702650, 0.707107, 0.711536, 0.715936, 0.720309, 0.724653, 0.728969, 0.733255, 0.737513, 0.741742, 0.745941, 0.750111, 0.754251, 0.758362, 0.762443, 0.766493, 0.770513, 0.774503, 0.778462, 0.782391, 0.786288, 0.790155, 0.793990, 0.797794, 0.801567, 0.805308, 0.809017, 0.812694, 0.816339, 0.819952, 0.823533, 0.827081, 0.830596, 0.834078, 0.837528, 0.840945, 0.844328, 0.847678, 0.850994, 0.854277, 0.857527, 0.860742, 0.863923, 0.867071, 0.870184, 0.873262, 0.876307, 0.879316, 0.882291, 0.885231, 0.888136, 0.891007, 0.893841, 0.896641, 0.899405, 0.902134, 0.904827, 0.907484, 0.910106, 0.912692, 0.915241, 0.917755, 0.920232, 0.922673, 0.925077, 0.927445, 0.929776, 0.932071, 0.934329, 0.936550, 0.938734, 0.940881, 0.942991, 0.945063, 0.947098, 0.949096, 0.951057, 0.952979, 0.954865, 0.956712, 0.958522, 0.960294, 0.962028, 0.963724, 0.965382, 0.967001, 0.968583, 0.970127, 0.971632, 0.973099, 0.974527, 0.975917, 0.977268, 0.978581, 0.979855, 0.981091, 0.982287, 0.983445, 0.984564, 0.985645, 0.986686, 0.987688, 0.988652, 0.989576, 0.990461, 0.991308, 0.992115, 0.992883, 0.993611, 0.994301, 0.994951, 0.995562, 0.996134, 0.996666, 0.997159, 0.997613, 0.998027, 0.998402, 0.998737, 0.999033, 0.999289, 0.999507, 0.999684, 0.999822, 0.999921, 0.999980, 1.000000, 0.999980, 0.999921, 0.999822, 0.999684, 0.999507, 0.999289, 0.999033, 0.998737, 0.998402, 0.998027, 0.997613, 0.997159, 0.996666, 0.996134, 0.995562, 0.994951, 0.994301, 0.993611, 0.992883, 0.992115, 0.991308, 0.990461, 0.989576, 0.988652, 0.987688, 0.986686, 0.985645, 0.984564, 0.983445, 0.982287, 0.981091, 0.979855, 0.978581, 0.977268, 0.975917, 0.974527, 0.973099, 0.971632, 0.970127, 0.968583, 0.967001, 0.965382, 0.963724, 0.962028, 0.960294, 0.958522, 0.956712, 0.954865, 0.952979, 0.951057, 0.949096, 0.947098, 0.945063, 0.942991, 0.940881, 0.938734, 0.936550, 0.934329, 0.932071, 0.929776, 0.927445, 0.925077, 0.922673, 0.920232, 0.917755, 0.915241, 0.912692, 0.910106, 0.907484, 0.904827, 0.902134, 0.899405, 0.896641, 0.893841, 0.891007, 0.888136, 0.885231, 0.882291, 0.879316, 0.876307, 0.873262, 0.870184, 0.867071, 0.863923, 0.860742, 0.857527, 0.854277, 0.850994, 0.847678, 0.844328, 0.840945, 0.837528, 0.834078, 0.830596, 0.827081, 0.823533, 0.819952, 0.816339, 0.812694, 0.809017, 0.805308, 0.801567, 0.797794, 0.793990, 0.790155, 0.786288, 0.782391, 0.778462, 0.774503, 0.770513, 0.766493, 0.762443, 0.758362, 0.754251, 0.750111, 0.745941, 0.741742, 0.737513, 0.733255, 0.728969, 0.724653, 0.720309, 0.715936, 0.711536, 0.707107, 0.702650, 0.698165, 0.693653, 0.689114, 0.684547, 0.679953, 0.675333, 0.670686, 0.666012, 0.661312, 0.656586, 0.651834, 0.647056, 0.642253, 0.637424, 0.632570, 0.627691, 0.622788, 0.617860, 0.612907, 0.607930, 0.602930, 0.597905, 0.592857, 0.587785, 0.582690, 0.577573, 0.572432, 0.567269, 0.562083, 0.556876, 0.551646, 0.546394, 0.541121, 0.535827, 0.530511, 0.525175, 0.519817, 0.514440, 0.509041, 0.503623, 0.498185, 0.492727, 0.487250, 0.481754, 0.476238, 0.470704, 0.465151, 0.459580, 0.453990, 0.448383, 0.442758, 0.437116, 0.431456, 0.425779, 0.420086, 0.414376, 0.408649, 0.402906, 0.397148, 0.391374, 0.385584, 0.379779, 0.373959, 0.368125, 0.362275, 0.356412, 0.350534, 0.344643, 0.338738, 0.332820, 0.326888, 0.320944, 0.314987, 0.309017, 0.303035, 0.297042, 0.291036, 0.285019, 0.278991, 0.272952, 0.266902, 0.260842, 0.254771, 0.248690, 0.242599, 0.236499, 0.230389, 0.224271, 0.218143, 0.212007, 0.205863, 0.199710, 0.193549, 0.187381, 0.181206, 0.175023, 0.168833, 0.162637, 0.156434, 0.150226, 0.144011, 0.137790, 0.131564, 0.125333, 0.119097, 0.112856, 0.106611, 0.100362, 0.094108, 0.087851, 0.081591, 0.075327, 0.069060, 0.062791, 0.056519, 0.050244, 0.043968, 0.037690, 0.031411, 0.025130, 0.018848, 0.012566, 0.006283, 0.000000, -0.006283, -0.012566, -0.018848, -0.025130, -0.031411, -0.037690, -0.043968, -0.050244, -0.056519, -0.062791, -0.069060, -0.075327, -0.081591, -0.087851, -0.094108, -0.100362, -0.106611, -0.112856, -0.119097, -0.125333, -0.131564, -0.137790, -0.144011, -0.150226, -0.156434, -0.162637, -0.168833, -0.175023, -0.181206, -0.187381, -0.193549, -0.199710, -0.205863, -0.212007, -0.218143, -0.224271, -0.230389, -0.236499, -0.242599, -0.248690, -0.254771, -0.260842, -0.266902, -0.272952, -0.278991, -0.285019, -0.291036, -0.297042, -0.303035, -0.309017, -0.314987, -0.320944, -0.326888, -0.332820, -0.338738, -0.344643, -0.350534, -0.356412, -0.362275, -0.368125, -0.373959, -0.379779, -0.385584, -0.391374, -0.397148, -0.402906, -0.408649, -0.414376, -0.420086, -0.425779, -0.431456, -0.437116, -0.442758, -0.448383, -0.453990, -0.459580, -0.465151, -0.470704, -0.476238, -0.481754, -0.487250, -0.492727, -0.498185, -0.503623, -0.509041, -0.514440, -0.519817, -0.525175, -0.530511, -0.535827, -0.541121, -0.546394, -0.551646, -0.556876, -0.562083, -0.567269, -0.572432, -0.577573, -0.582690, -0.587785, -0.592857, -0.597905, -0.602930, -0.607930, -0.612907, -0.617860, -0.622788, -0.627691, -0.632570, -0.637424, -0.642253, -0.647056, -0.651834, -0.656586, -0.661312, -0.666012, -0.670686, -0.675333, -0.679953, -0.684547, -0.689114, -0.693653, -0.698165, -0.702650, -0.707107, -0.711536, -0.715936, -0.720309, -0.724653, -0.728969, -0.733255, -0.737513, -0.741742, -0.745941, -0.750111, -0.754251, -0.758362, -0.762443, -0.766493, -0.770513, -0.774503, -0.778462, -0.782391, -0.786288, -0.790155, -0.793990, -0.797794, -0.801567, -0.805308, -0.809017, -0.812694, -0.816339, -0.819952, -0.823533, -0.827081, -0.830596, -0.834078, -0.837528, -0.840945, -0.844328, -0.847678, -0.850994, -0.854277, -0.857527, -0.860742, -0.863923, -0.867071, -0.870184, -0.873262, -0.876307, -0.879316, -0.882291, -0.885231, -0.888136, -0.891007, -0.893841, -0.896641, -0.899405, -0.902134, -0.904827, -0.907484, -0.910106, -0.912692, -0.915241, -0.917755, -0.920232, -0.922673, -0.925077, -0.927445, -0.929776, -0.932071, -0.934329, -0.936550, -0.938734, -0.940881, -0.942991, -0.945063, -0.947098, -0.949096, -0.951057, -0.952979, -0.954865, -0.956712, -0.958522, -0.960294, -0.962028, -0.963724, -0.965382, -0.967001, -0.968583, -0.970127, -0.971632, -0.973099, -0.974527, -0.975917, -0.977268, -0.978581, -0.979855, -0.981091, -0.982287, -0.983445, -0.984564, -0.985645, -0.986686, -0.987688, -0.988652, -0.989576, -0.990461, -0.991308, -0.992115, -0.992883, -0.993611, -0.994301, -0.994951, -0.995562, -0.996134, -0.996666, -0.997159, -0.997613, -0.998027, -0.998402, -0.998737, -0.999033, -0.999289, -0.999507, -0.999684, -0.999822, -0.999921, -0.999980, -1.000000, -0.999980, -0.999921, -0.999822, -0.999684, -0.999507, -0.999289, -0.999033, -0.998737, -0.998402, -0.998027, -0.997613, -0.997159, -0.996666, -0.996134, -0.995562, -0.994951, -0.994301, -0.993611, -0.992883, -0.992115, -0.991308, -0.990461, -0.989576, -0.988652, -0.987688, -0.986686, -0.985645, -0.984564, -0.983445, -0.982287, -0.981091, -0.979855, -0.978581, -0.977268, -0.975917, -0.974527, -0.973099, -0.971632, -0.970127, -0.968583, -0.967001, -0.965382, -0.963724, -0.962028, -0.960294, -0.958522, -0.956712, -0.954865, -0.952979, -0.951057, -0.949096, -0.947098, -0.945063, -0.942991, -0.940881, -0.938734, -0.936550, -0.934329, -0.932071, -0.929776, -0.927445, -0.925077, -0.922673, -0.920232, -0.917755, -0.915241, -0.912692, -0.910106, -0.907484, -0.904827, -0.902134, -0.899405, -0.896641, -0.893841, -0.891007, -0.888136, -0.885231, -0.882291, -0.879316, -0.876307, -0.873262, -0.870184, -0.867071, -0.863923, -0.860742, -0.857527, -0.854277, -0.850994, -0.847678, -0.844328, -0.840945, -0.837528, -0.834078, -0.830596, -0.827081, -0.823533, -0.819952, -0.816339, -0.812694, -0.809017, -0.805308, -0.801567, -0.797794, -0.793990, -0.790155, -0.786288, -0.782391, -0.778462, -0.774503, -0.770513, -0.766493, -0.762443, -0.758362, -0.754251, -0.750111, -0.745941, -0.741742, -0.737513, -0.733255, -0.728969, -0.724653, -0.720309, -0.715936, -0.711536, -0.707107, -0.702650, -0.698165, -0.693653, -0.689114, -0.684547, -0.679953, -0.675333, -0.670686, -0.666012, -0.661312, -0.656586, -0.651834, -0.647056, -0.642253, -0.637424, -0.632570, -0.627691, -0.622788, -0.617860, -0.612907, -0.607930, -0.602930, -0.597905, -0.592857, -0.587785, -0.582690, -0.577573, -0.572432, -0.567269, -0.562083, -0.556876, -0.551646, -0.546394, -0.541121, -0.535827, -0.530511, -0.525175, -0.519817, -0.514440, -0.509041, -0.503623, -0.498185, -0.492727, -0.487250, -0.481754, -0.476238, -0.470704, -0.465151, -0.459580, -0.453990, -0.448383, -0.442758, -0.437116, -0.431456, -0.425779, -0.420086, -0.414376, -0.408649, -0.402906, -0.397148, -0.391374, -0.385584, -0.379779, -0.373959, -0.368125, -0.362275, -0.356412, -0.350534, -0.344643, -0.338738, -0.332820, -0.326888, -0.320944, -0.314987, -0.309017, -0.303035, -0.297042, -0.291036, -0.285019, -0.278991, -0.272952, -0.266902, -0.260842, -0.254771, -0.248690, -0.242599, -0.236499, -0.230389, -0.224271, -0.218143, -0.212007, -0.205863, -0.199710, -0.193549, -0.187381, -0.181206, -0.175023, -0.168833, -0.162637, -0.156434, -0.150226, -0.144011, -0.137790, -0.131564, -0.125333, -0.119097, -0.112856, -0.106611, -0.100362, -0.094108, -0.087851, -0.081591, -0.075327, -0.069060, -0.062791, -0.056519, -0.050244, -0.043968, -0.037690, -0.031411, -0.025130, -0.018848, -0.012566, -0.006283, 0.0};

// bounds the angle t to be within the range [0, 2*PI)
//  where t is can be an angle on the range (-inf, inf)
float boundAngle(float t) {
    float nf = t/(2*PI);
    int n = (nf < 0) ? nf - 1 : nf;

    return t - n*2*PI;
}

int toTableIndex(float input) {
    int degrees = (int)(boundAngle(input)*TABLESIZE/((float)PI*2));
    
    if (degrees < 0) return 0;
    if (degrees > TABLESIZE) return TABLESIZE;
    
    return degrees;
}
    
float rsin(float input) {
    return sinTable[toTableIndex(input)];
}

float rcos(float input) {
    return sinTable[(toTableIndex(input) + TABLESIZE/4)%TABLESIZE];
}
