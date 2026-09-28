void main() {
    vec2 pos = gl_FragCoord.xy / 50.0;
    float d = length(pos - vec2(0.5));
    gl_FragColor = (d < 0.2) ? vec4(1.0) : vec4(0.0);
}