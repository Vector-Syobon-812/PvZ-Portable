package io.github.wszqkzqk.pvzportable;

import android.os.Bundle;
import android.util.Log;

import org.libsdl.app.SDLActivity;

import java.io.File;

/**
 * PvZ Portable Android entry point.
 *
 * Game resources (main.pak, properties/, etc.) should be placed by the user
 * into the app's external files directory:
 *   Android/data/io.github.wszqkzqk.pvzportable/files/
 *
 * This directory is accessible via a file manager on most devices.
 */
public class PvZPortableActivity extends SDLActivity {
    private static final String TAG = "PvZPortable";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // Ensure the external files directory exists before SDL starts
        File extDir = getExternalFilesDir(null);
        if (extDir != null && !extDir.exists()) {
            extDir.mkdirs();
        }

        Log.i(TAG, "Resource directory: " + (extDir != null ? extDir.getAbsolutePath() : "null"));

        super.onCreate(savedInstanceState);
    }

    @Override
    protected String[] getLibraries() {
        return new String[]{
            "SDL2",
            "main"
        };
    }
}
