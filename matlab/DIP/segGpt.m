% Read the input image
img = imread('22.jpg');
% Convert the image to grayscale
gray_img = rgb2gray(img);

% Apply Canny edge detection
edges = edge(gray_img, 'Canny');

% Initialize the region growing parameters
threshold = 30; % Intensity threshold for region growing
visited = false(size(gray_img)); % Array to keep track of visited pixels

% Perform region growing
[row, col] = find(edges);
for k = 1:length(row)
    if ~visited(row(k), col(k)) % Check if the pixel is visited
        region = region_grow(gray_img, [row(k), col(k)], threshold);
        img(region) = 255; % Set the pixels in the region to white
    end
end

% Display the result
figure;
subplot(1, 2, 1), imshow(img), title('Original Image');
subplot(1, 2, 2), imshow(edges), title('Canny Edges');

% Function for region growing
function region = region_grow(img, seed, threshold)
    [rows, cols] = size(img);
    region = false(rows, cols);
    stack = zeros(rows*cols, 2);
    stack_pos = 1;
   
    % Push the seed pixel onto the stack
    stack(stack_pos, :) = seed;
    stack_pos = stack_pos + 1;
   
    % Get the seed pixel intensity
    seed_intensity = img(seed(1), seed(2));
   
    % Define 8-connectivity neighborhood
    neighbors = [-1, -1; -1, 0; -1, 1; 0, -1; 0, 1; 1, -1; 1, 0; 1, 1];
   
    while stack_pos > 1
        % Pop the pixel from the stack
        stack_pos = stack_pos - 1;
        pixel = stack(stack_pos, :);
       
        % Check if the pixel is within the image boundaries and unvisited
        if pixel(1) >= 1 && pixel(1) <= rows && pixel(2) >= 1 && pixel(2) <= cols && ~region(pixel(1), pixel(2))
            % Get the pixel intensity
            pixel_intensity = img(pixel(1), pixel(2));
           
            % Check the intensity difference with the seed pixel
            if abs(pixel_intensity - seed_intensity) <= threshold
                % Add the pixel to the region
                region(pixel(1), pixel(2)) = true;
               
                % Push the neighboring pixels onto the stack
                for n = 1:size(neighbors, 1)
                    neighbor = pixel + neighbors(n, :);
                    stack(stack_pos, :) = neighbor;
                    stack_pos = stack_pos + 1;
                end
            end
        end
    end
end