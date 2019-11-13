using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Android;

public class WebcamReader : MonoBehaviour
{
    [SerializeField] private RawImage webcamTarget;

    private WebCamTexture webcamTexture;
    private Texture2D bufferTexture;
    private Color32[] textureMap;
    private Texture2D Frame { get; set; }

    void Start()
    {
#if PLATFORM_ANDROID
        if (!Permission.HasUserAuthorizedPermission(Permission.Camera))
        {
            Permission.RequestUserPermission(Permission.Camera);
        }
#endif

        WebCamDevice[] devices = WebCamTexture.devices;

        if (!webcamTarget && GetComponent<RawImage>()) webcamTarget = GetComponent<RawImage>();

        webcamTexture = new WebCamTexture(devices[0].name);
        webcamTexture.Play();
    }

    void Update()
    {
        if(!webcamTexture.isPlaying) webcamTexture.Play();
        UpdateFrame();
    }

    private void UpdateFrame()
    {
        if (!bufferTexture || bufferTexture.width >= 16)
        {
            bufferTexture = new Texture2D(webcamTexture.width, webcamTexture.height);

            webcamTarget.material.mainTexture = bufferTexture;
            webcamTarget.texture = bufferTexture;
        }

        textureMap = webcamTexture.GetPixels32();
        ProcessFrame(textureMap);

        bufferTexture.SetPixels32(textureMap);
        bufferTexture.Apply();

        Frame = bufferTexture;
    }

    virtual protected void ProcessFrame(Color32[] frame)
    {
        return;
    }
}
