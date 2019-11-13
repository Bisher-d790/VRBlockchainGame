using UnityEngine;

public class SkinIsolator : WebcamReader
{
    [SerializeField]
    [Range(0, 100)]
    private float sensitivity = 50;

    public bool isMasked = true;

    public void SwitchIsMasked() { isMasked = !isMasked; }

    protected override void ProcessFrame(Color32[] frame)
    {
        for (int i = 0; i < frame.Length; i++)
        {
            Color32 pixel = frame[i];

            // Invert the colors
            pixel = new Color32(
                pixel.b,
                pixel.g,
                pixel.r,
                pixel.a
                );

            if (pixel.b - pixel.r > 100 - sensitivity) { pixel = Color.black; }
            else if (isMasked) { pixel = Color.white; }

            frame[i] = pixel;
        }

    }
}
